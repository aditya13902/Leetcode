class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        for(auto ele:nums){
            if((ele&1)==0){
                sum+=ele;
            }
        }
        vector<int>ans;
        for(auto vec:queries){
            int val=vec[0];
            int idx=vec[1];
            if(nums[idx]%2==0){
                sum-=nums[idx];
            }
            nums[idx]+=val;
            if(nums[idx]%2==0){
                sum+=nums[idx];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};