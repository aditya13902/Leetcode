class Solution {
private:
    vector<int>par;
public:
    int find(int v){
        if(par[v]==v) return v;
        return par[v]=find(par[v]);
    }
    bool Union(int u,int v){
        u=find(u);
        v=find(v);
        if(u!=v){
            par[v]=u;
            return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.resize(n+1);
        for(int i=1;i<=n;i++) par[i]=i;
        
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            if(!Union(u,v)){
                return {u,v};
            }
        }
        return {};
    }
};