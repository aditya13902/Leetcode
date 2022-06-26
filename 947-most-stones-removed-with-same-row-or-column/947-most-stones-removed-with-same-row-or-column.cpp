class Solution {
public:
    unordered_map<int,int>mx;
    unordered_map<int,int>my;
    vector<int>vis;
    void dfs(vector<vector<int>>&adj,int i){
        if(vis[i]){
            return;
        }
        vis[i]=1;
        for(auto ele:adj[i]){
            dfs(adj,ele);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            int x=stones[i][0];
            int y=stones[i][1];
            if(mx.find(x)==mx.end() && my.find(y)==my.end()){
                mx[x]=i;
                my[y]=i;
            }
            else{
                if(mx.find(x)!=mx.end() && my.find(y)!=my.end()){
                    adj[mx[x]].push_back(i);
                    adj[i].push_back(mx[x]);
                    adj[my[y]].push_back(i);
                    adj[i].push_back(my[y]);
                    adj[mx[x]].push_back(my[y]);
                    adj[my[y]].push_back(mx[x]);
                }
                else if(mx.find(x)!=mx.end()){
                    adj[mx[x]].push_back(i);
                    adj[i].push_back(mx[x]);
                    my[y]=i;
                }
                else if(my.find(y)!=my.end()){
                    adj[my[y]].push_back(i);
                    adj[i].push_back(my[y]);
                    mx[x]=i;
                }
            }
        }
        vis.resize(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i);
                cnt++;
            }
        }
        return n-cnt;
    }
};