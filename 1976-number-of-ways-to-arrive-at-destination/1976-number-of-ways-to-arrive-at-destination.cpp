class Solution {
public:
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>>adj(n);
        for(auto vec:roads){
            adj[vec[0]].push_back({vec[1],vec[2]});
            adj[vec[1]].push_back({vec[0],vec[2]});
        }
        vector<long long>dis(n,1e18);
        vector<long long>cnt(n,0);
        set<pair<long long,long long>>st;
        st.insert({0,0});
        dis[0]=0;
        cnt[0]=1;
        while(st.size()){
            auto it=*(st.begin());
            st.erase(st.begin());
            long long v=it.second;
            long long d=it.first;
            for(auto ele:adj[v]){
                if(dis[ele.first]>d+ele.second){
                    dis[ele.first]=d+ele.second;
                    cnt[ele.first]=(cnt[v])%mod;
                    st.insert({dis[ele.first],ele.first});
                }
                else if(dis[ele.first]==d+ele.second){
                    dis[ele.first]=d+ele.second;
                    cnt[ele.first]=(cnt[ele.first]+cnt[v])%mod;
                    st.insert({dis[ele.first],ele.first});
                }
            }
        }
        return cnt[n-1];
    }
};





