class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int s=0;
        int e=nums.size()-1;
        int idx1=-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]<target){
                s=m+1;
            }
            else if(nums[m]>target){
                e=m-1;
            }
            else{
                idx1=m;
                e=m-1;
            }
        }
        ans.push_back(idx1);
        int idx2=-1;
        s=0;
        e=nums.size()-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]<target){
                s=m+1;
            }
            else if(nums[m]>target){
                e=m-1;
            }
            else{
                idx2=m;
                s=m+1;
            }
        }
        ans.push_back(idx2);
        return ans;
    }
};