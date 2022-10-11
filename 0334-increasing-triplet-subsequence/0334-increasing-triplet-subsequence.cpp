// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         if(nums.size()<3) return false;
//         vector<int>lft(nums.size(),INT_MAX);
//         vector<int>rgt(nums.size(),INT_MIN);
//         int curr=INT_MAX;
//         for(int i=0;i<nums.size();i++){
//             lft[i]=curr;
//             curr=min(curr,nums[i]);
//         }
//         curr=INT_MIN;
//         for(int i=nums.size()-1;i>=0;i--){
//             rgt[i]=curr;
//             curr=max(curr,nums[i]);
//         }
//         for(int i=1;i<=nums.size()-2;i++){
//             if(lft[i]<nums[i] && rgt[i]>nums[i]){
//                 return true;
//             }
//         }
//         return false;
        
//     }
// };
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num1=INT_MAX;
        int num2=INT_MAX;
        for(auto ele:nums){
            if(ele<num1){
                num1=ele;
            }
            else if(ele>num1 && ele<num2){
                num2=ele;
            }
            else if(ele>num2){
                return true;
            }
        }
        return false;
    }
};