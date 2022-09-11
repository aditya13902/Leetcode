const int mod=1e9+7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({eff[i],speed[i]});
        }
        sort(vec.begin(),vec.end(),greater<pair<int,int>>());
        set<pair<int,int>>st;
        long long sum=0;
        long long ans=0;
        for(auto [e,s]:vec){
            if(st.size()==k){
                sum-=(*st.begin()).first;
                st.erase(st.begin());
            }
            st.insert({s,e});
            sum=(sum+s);
            ans=max(ans,(e*sum));
        }
        return ans%mod;
    }
};