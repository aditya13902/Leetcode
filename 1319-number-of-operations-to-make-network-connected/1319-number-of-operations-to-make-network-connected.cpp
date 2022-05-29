class Solution {
public:
    vector<int>parent;
    int find(int v){
        if(parent[v]==v){
            return v;
        }
        return parent[v]=find(parent[v]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto vec:connections){
            int a=vec[0];
            int b=vec[1];
            a=find(a);
            b=find(b);
            if(a!=b){
                parent[a]=b;
            }
            
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                cnt++;
            }
        }
        return cnt-1;
        
    }
};