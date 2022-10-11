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