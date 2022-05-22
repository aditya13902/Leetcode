class Solution {
public:
    map<pair<int,int>,int>mp;
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto vec:connections){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
            mp[{vec[0],vec[1]}]=1;
        }
        vector<int>vis(n,0);
        queue<int>q;
        q.push(0);
        int cnt=0;
        vis[0]=1;
        while(q.size()){
            int ele=q.front();
            q.pop();
            for(auto v:adj[ele]){
                if(vis[v]){
                    continue;
                }
                if(mp.find({v,ele})==mp.end()){
                    // cout<<v<<"-"<<ele<<endl;
                    cnt++;
                }
                q.push(v);
                vis[v]=1;
            }
        }
        return cnt;
    }
};