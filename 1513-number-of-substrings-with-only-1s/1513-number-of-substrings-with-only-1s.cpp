class Solution {
public:
    const int mod=1e9+7;
    int numSub(string s) {
        int cnt=0;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                ans=(ans+((cnt*1LL*(cnt+1))/2))%mod;
                cnt=0;
            }
            else{
                cnt++;
            }
        }
        ans=(ans+((cnt*1LL*(cnt+1))/2))%mod;
        return ans;
    }
};
// 1 1 1 1 1 