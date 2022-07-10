class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),1);
        vector<int>hash(nums.size(),0);
        int mx=1;
        int idx=0;
        for(int i=1;i<nums.size();i++){
            hash[i]=i;
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]) continue;
                if(dp[i]<dp[j]+1){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(mx<dp[i]){
                mx=dp[i];
                idx=i;
            }
        }
        vector<int>ans;
        while(idx!=hash[idx]){
            ans.push_back(nums[idx]);
            idx=hash[idx];
        }
        ans.push_back(nums[idx]);
        return ans;
    }
};