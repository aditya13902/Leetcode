class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n,0);
        int mx=1;
        int lstidx=0;
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i] && dp[i]<1+dp[j]){
                    hash[i]=j;
                    dp[i]=1+dp[j];
                }
            }
            if(mx<dp[i]){
                mx=dp[i];
                lstidx=i;
            }
        }
        // while(hash[lstidx]!=lstidx){
        //     cout<<nums[lstidx]<<" ";
        //     lstidx=hash[lstidx];
        // }
        // cout<<endl;
        return mx;
    }
};