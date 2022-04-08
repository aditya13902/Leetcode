class Solution {
    vector<vector<int>>dp;
public:
    int helper(vector<int>&prices,int fee,bool flag,int idx){
        if(idx>=prices.size()){
            return 0;
        }
        if(dp[idx][flag]!=-1){
            return dp[idx][flag];
        }
        if(flag){
            dp[idx][flag]=max(-prices[idx]-fee+helper(prices,fee,!flag,idx+1),helper(prices,fee,flag,idx+1));
        }
        else{
            dp[idx][flag]=max(prices[idx]+helper(prices,fee,!flag,idx+1),helper(prices,fee,flag,idx+1));
        }
        return dp[idx][flag];
    }
    
    int maxProfit(vector<int>& prices, int fee) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return helper(prices,fee,true,0);
        
    }
};