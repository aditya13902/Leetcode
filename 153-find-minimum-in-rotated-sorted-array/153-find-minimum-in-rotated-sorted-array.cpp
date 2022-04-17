class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int ans=0;
        while(i<=j){
            int m=i+(j-i)/2;
            if(nums[m]<nums[0]){
                ans=m;
                j=m-1;
            }
            else{
                i=m+1;
            }
        }
        return nums[ans];
    }
};