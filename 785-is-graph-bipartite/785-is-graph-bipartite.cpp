class Solution {
public:
    bool bi(vector<int>&color,vector<vector<int>>&graph,int node)
    {
        if(color[node]==-1)
            color[node]=0;
        for(auto it:graph[node])
        {
            if(color[it]==-1)
            {
                color[it]=1-color[node];
                if(!bi(color,graph,it))
                    return false;
            }
            else
            {
                if(color[it]==color[node])
                    return false;
                
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!bi(color,graph,i))
                    return false;
            }
        }
        return true;
        
    }
};