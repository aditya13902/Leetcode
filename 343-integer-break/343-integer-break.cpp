class Solution {
public:
    unordered_map<int,int>mp;
    int helper(int n,int cnt){
        if(n==0) return cnt>1;
        int ans=0;
        if(mp.find(n)!=mp.end()) return mp[n];
        for(int i=1;i<=n;i++){
            ans=max(ans,i*helper(n-i,cnt+1));
        }
        return mp[n]=ans;
    }
    int integerBreak(int n) {
        return helper(n,0);
    }
};