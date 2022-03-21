class Solution {
public:
    vector<int>parent;
    int getParent(int v){
        if(v==parent[v]){
            return v;
        }
        return getParent(parent[v]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        vector<int>ans;
        for(auto vec:edges){
            int a=getParent(vec[0]);
            int b=getParent(vec[1]);
            if(a!=b){
                parent[b]=a;
            }
            else{
                ans=vec;
                break;
            }
        }
        
        return ans;
    }
};