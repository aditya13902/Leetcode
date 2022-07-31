class Solution {
public:

    int maxCount = -1;
    int count = 0;

    int DFS(vector<vector<int>>& adj, vector<int>& visited, vector<int>& dfsVisit, int cur, int parent, vector<int>& number)
    {
        visited[cur] = 1;
        dfsVisit[cur] = 1;
        count++;
        number[cur] = count;

        for(int x : adj[cur])
        {
            if(!visited[x])
            {
                int value = DFS(adj, visited, dfsVisit, x, cur, number);
                dfsVisit[cur] = 0;
                return value;
            }

            else if(dfsVisit[x])
            {
                // cycle is detected --> get the length of cycle
                dfsVisit[x] = 0;
                return number[cur] - number[x] + 1;    
            }

        }

        dfsVisit[cur] = 0;
        return 0;
    }

    int longestCycle(vector<int>& edges) {

        int n = edges.size();
        // convert into "adjcency list" graph format for my ease :)
        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        vector<int> dfsVisit(n, 0);
        vector<int> number(n, 0);

        for(int i=0; i<n; i++)
        {
            if(edges[i] != -1)
                adj[i].push_back(edges[i]);
        }

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                maxCount = max(maxCount, DFS(adj, visited, dfsVisit, i, -1, number));
                // reseting count variable for next iteration of unvisited node
                count = 0;
            }
        }

        return (maxCount == 0) ? -1 : maxCount;
    }
};