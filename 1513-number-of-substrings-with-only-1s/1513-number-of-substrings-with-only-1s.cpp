class Solution {
public:
    const int mod=1e9+7;
    int add(int a,int b){
        return (a+b)%mod;
    }
    int numSub(string s) {
        int cnt=0;
        long long ans=0;
        for(int i=0;i<s.size();i++){
            cnt=(s[i]=='1')?(cnt+1):0;
            ans=add(ans,cnt);
        }
        return ans;
    }
};
// 1 1 1 1 1 