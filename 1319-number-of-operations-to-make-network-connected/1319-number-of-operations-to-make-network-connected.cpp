class Solution {
public:
    vector<int>parent;
    int getParent(int v){
        if(v==parent[v]){
            return v;
        }
        return getParent(parent[v]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // int n=connections.size();
        if(connections.size()<n-1){
            return -1;
        }
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int cnt=0;
        for(auto vec:connections){
            int a=getParent(vec[0]);
            int b=getParent(vec[1]);
            if(a!=b){
                parent[a]=b;
            }
            else{
                cnt++;
            }
        }
        int cnt2=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                cnt2++;
            }
        }
        return min(cnt,cnt2-1);
    }
};