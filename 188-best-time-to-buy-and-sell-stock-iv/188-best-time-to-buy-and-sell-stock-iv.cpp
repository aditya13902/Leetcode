class Solution {
public:
    vector<vector<vector<int>>>dp;
    int func(vector<int>&prices,int idx,int k,int f){
        if(k==0 || idx==prices.size()) return 0;
        if(dp[idx][k][f]!=-1){
            return dp[idx][k][f];
        }
        if(f){
            return dp[idx][k][f]=max(func(prices,idx+1,k,f),-prices[idx]+func(prices,idx+1,k,!f));
        }
        else{
            return dp[idx][k][f]=max(func(prices,idx+1,k,f),prices[idx]+func(prices,idx+1,k-1,!f));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        dp.resize(prices.size(),vector<vector<int>>(k+1,vector<int>(2,-1)));
        return func(prices,0,k,1);
    }
};