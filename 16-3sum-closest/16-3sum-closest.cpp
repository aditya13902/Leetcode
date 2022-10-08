class Solution {
public:
    // -4 -1 1 2
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int curr=-1;
        for(int i=0;i<nums.size()-2;i++){
            int j=i+1;
            int k=nums.size()-1;
            // int diff=abs(sum-target);
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<ans){
                    curr=sum;
                    ans=abs(sum-target);
                }
                if(sum>target){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return curr;
    }
};