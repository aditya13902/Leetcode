class Solution {
public:
    vector<int>parent;
    int getParent(int v){
        if(v==parent[v]){
            return v;
        }
        return getParent(parent[v]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    int a=getParent(i);
                    int b=getParent(j);
                    if(a!=b){
                        parent[b]=a;
                    }
                }
                
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        return cnt;
    }
};