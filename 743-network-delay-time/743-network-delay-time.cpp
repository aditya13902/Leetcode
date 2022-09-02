class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto vec:times){
            adj[vec[0]].push_back({vec[1],vec[2]});
        }
        vector<int>dis(n+1,1e8);
        dis[k]=0;
        set<pair<int,int>>st;
        st.insert({0,k});
        vector<int>vis(n+1,0);
        while(st.size()){
            auto curr=*(st.begin());
            st.erase(st.begin());
            if(vis[curr.second]) continue;
            vis[curr.second]=1;
            for(auto ele:adj[curr.second]){
                if(dis[ele.first]>dis[curr.second]+ele.second){
                    dis[ele.first]=dis[curr.second]+ele.second;
                    st.insert({dis[ele.first],ele.first});
                }
            }
        }
        int mx=INT_MIN;
        for(int i=1;i<=n;i++){
            mx=max(dis[i],mx);
        }
        return mx==1e8?-1:mx;
    }
};