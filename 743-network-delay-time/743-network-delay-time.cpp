class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto vec:times){
            adj[vec[0]].push_back({vec[1],vec[2]});
        }
        set<pair<int,int>>st;
        st.insert({0,k});
        vector<int>vis(n+1,0);
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        while(st.size()){
            auto [d,v]=*(st.begin());
            st.erase(st.begin());
            if(vis[v]){
                continue;
            }
            vis[v]=1;
            for(auto [child_v,child_d]:adj[v]){
                if(d+child_d<dis[child_v]){
                    dis[child_v]=d+child_d;
                    st.insert({dis[child_v],child_v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX){
                return -1;
            }
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};