class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int ans=nums[0];
        while(i<=j){
            int m=i+(j-i)/2;
            if(nums[m]>=nums[0]){
                i=m+1;
            }
            else{
                ans=nums[m];
                j=m-1;
            }
        }
        return ans;
    }
};