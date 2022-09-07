class Solution {
public:
    vector<int>col;
    bool bfs(vector<vector<int>>&graph,int v){
        queue<pair<int,int>>q;
        q.push({v,0});
        col[v]=0;
        while(q.size()){
            int l=q.size();
            while(l--){
                auto curr=q.front();
                int node=curr.first;
                int val=curr.second;
                q.pop();
                for(auto ele:graph[node]){
                    if(col[ele]!=-1){
                        if(col[ele]==val) return false;
                        continue;
                    }
                    col[ele]=!val;
                    q.push({ele,!val});
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        col.resize(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(col[i]==-1){
                if(!bfs(graph,i)) return false;
            }
        }
        return true;
    }
};