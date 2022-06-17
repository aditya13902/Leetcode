class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),1);
        vector<int>hash(nums.size());
        for(int i=0;i<nums.size();i++){
            hash[i]=i;
        }
        int ans=0;
        int lastidx=0;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]){
                    continue;
                }
                if(dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
                
                
            }
            if(dp[i]>ans){
                lastidx=i;
                ans=dp[i];
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastidx]);
        while(hash[lastidx]!=lastidx){
            lastidx=hash[lastidx];
            temp.push_back(nums[lastidx]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};