class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int sum=0;
        int curr=0;
        int i=0;
        int ans=0;
        for(int j=0;j<nums.size();j++){
            while(curr&nums[j]){
                sum-=nums[i];
                curr&=(~nums[i]);
                i++;
            }
            sum+=nums[j];
            curr|=nums[j];
            ans=max(ans,(j-i+1));
        }
        return ans;
    }
};