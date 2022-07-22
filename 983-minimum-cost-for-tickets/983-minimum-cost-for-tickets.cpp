class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(396,0);
        unordered_map<int,int> mp;
        for(int a:days)
            mp[a]=1;
        for(int i=1;i<=395;i++)
        {
            if(mp.count(i)==0)
                dp[i]=dp[i-1];
            else
                dp[i]=dp[i-1]+costs[0];
            if(i>=7)
                dp[i]=min(dp[i],dp[i-7]+costs[1]);
            if(i>=30)
                dp[i]=min(dp[i],dp[i-30]+costs[2]);
        }
        return dp[395];
    }
};