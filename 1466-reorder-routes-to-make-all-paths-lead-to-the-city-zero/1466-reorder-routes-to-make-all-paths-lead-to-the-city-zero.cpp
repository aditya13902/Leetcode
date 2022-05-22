class Solution {
public:
    map<pair<int,int>,int>mp;
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        vector<unordered_map<int,int>>mp(n);
        for(auto vec:connections){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
            mp[vec[0]][vec[1]]=1;
        }
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        int cnt=0;
        while(q.size()){
            int ele=q.front();
            q.pop();
            vis[ele]=1;
            for(auto v:adj[ele]){
                if(vis[v]){
                    continue;
                }
                if(mp[v][ele]==0){
                    // cout<<v<<"-"<<ele<<endl;
                    cnt++;
                }
                q.push(v);
                
            }
        }
        return cnt;
    }
};