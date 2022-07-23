class Solution {
public:
    vector<vector<int>>dp;
    int helper(int eggs,int floor){
        if(floor==0) return 0;
        if(eggs==1) return floor;
        if(dp[eggs][floor]!=-1) return dp[eggs][floor];
        int ans=floor;
        int l=1;
        int r=floor;
        while(l<=r){
            int m=(l+r)/2;
            int lft=helper(eggs-1,m-1);
            int rgt=helper(eggs,floor-m);
            if(lft<rgt){
                l=m+1;
            }
            else{
                r=m-1;
            }
            ans=min(ans,1+max(lft,rgt));
        }
        return dp[eggs][floor]=ans;
    }
    int superEggDrop(int k, int n) {
        dp.resize(k+1,vector<int>(n+1,-1));
        return helper(k,n);
    }
};