class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        // unordered_map<int,int>mp;
        int mx=0;
        vector<pair<int,int>>dp(nums.size());
        for(int i=0;i<nums.size();i++){
            dp[i]={1,1};
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i].first<=dp[j].first+1){
                        if(dp[i].first==dp[j].first+1){
                            (dp[i].second)+=dp[j].second;
                        }
                        else{
                            dp[i]={dp[j].first+1,dp[j].second};
                        }
                    }
                }
            }
            mx=max(dp[i].first,mx);
        }
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(dp[i].first==mx){
                cnt+=dp[i].second;
            }
        }
        return cnt;
    }
};