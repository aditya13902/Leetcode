class Solution {
public:
    vector<int>parent;
    int getP(int v){
        if(parent[v]==v){
            return v;
        }
        return getP(parent[v]);
    }
    bool merge(int v1,int v2){
        v1=getP(v1);
        v2=getP(v2);
        if(v1!=v2){
            parent[v1]=v2;
            return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size()+1);
        for(int i=1;i<=edges.size();i++){
            parent[i]=i;
        }
        vector<int>ans;
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];
            if(!merge(u,v)){
                ans=vec;
                break;
            }
        }
        return ans;
    }
};