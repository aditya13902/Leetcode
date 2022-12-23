class Solution {
public:
    // int maxfunc(vector<int>& prices,int i,int f,vector<vector<int>>&dp){
    //     if(i>=prices.size()) return 0;
    //     if(dp[i][f]!=-1) return dp[i][f];
    //     int ans=maxfunc(prices,i+1,f,dp);
    //     if(f){
    //         ans=max(ans,-prices[i]+maxfunc(prices,i+1,!f,dp));
    //     }
    //     else{
    //         ans=max(ans,prices[i]+maxfunc(prices,i+2,!f,dp));
    //     }
    //     return dp[i][f]=ans;
    // }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>prev2(2,0);
        vector<int>prev1(2,0);
        for(int i=n-1;i>=0;i--){
            vector<int>curr(2,0);
            for(int f=0;f<2;f++){
                curr[f]=prev1[f];
                if(f){
                    curr[f]=max(curr[f],-prices[i]+prev1[!f]);
                }
                else{
                    curr[f]=max(curr[f],prices[i]+prev2[!f]);
                }
            }
            prev2=prev1;
            prev1=curr;
        }
        return prev1[1];
    }
};