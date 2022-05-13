class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>&prices,int fee,int idx,int f){
        if(idx>=prices.size()){
            return 0;
        }
        if(dp[idx][f]!=-1){
            return dp[idx][f];
        }
        if(f==0){
            return dp[idx][f]= max(-prices[idx]+helper(prices,fee,idx+1,!f),helper(prices,fee,idx+1,f));
        }
        else{
            return dp[idx][f]=max(prices[idx]-fee+helper(prices,fee,idx+1,!f),helper(prices,fee,idx+1,f));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return helper(prices,fee,0,0);
    }
};