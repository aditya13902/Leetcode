class Solution {
private:
    int helper(vector<int>&arr){
        if(arr.size()==0) return 0;
        if(arr.size()==1) return arr[0];
        vector<int>dp(arr.size());
        dp[0]=arr[0];
        dp[1]=max(arr[1],arr[0]);
        for(int i=2;i<arr.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
        }
        return dp[arr.size()-1];
    }
public:
    int rob(vector<int>& nums) {
        vector<int> start;
        vector<int> end;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                start.push_back(nums[i]);
            }
            else if(i==nums.size()-1){
                end.push_back(nums[i]);
            }
            else{
                start.push_back(nums[i]);
                end.push_back(nums[i]);
            }
        }
        return max(helper(start),helper(end));
    }
};