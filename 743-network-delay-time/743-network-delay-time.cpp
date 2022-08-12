class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto vec:times){
            adj[vec[0]].push_back({vec[1],vec[2]});
        }
        vector<int>dis(n+1,1e8);
        vector<int>vis(n+1,0);
        set<pair<int,int>>st;
        dis[k]=0;
        st.insert({0,k});
        while(st.size()){
            auto curr=*(st.begin());
            st.erase(st.begin());
            int v=curr.second;
            int d=curr.first;
            if(vis[v]) continue;
            vis[v]=1;
            for(auto ele:adj[v]){
                int ele_v=ele.first;
                int ele_d=ele.second;
                if(dis[ele_v]>dis[v]+ele_d){
                    dis[ele_v]=dis[v]+ele_d;
                    st.insert({dis[ele_v],ele_v});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==1e8) return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};