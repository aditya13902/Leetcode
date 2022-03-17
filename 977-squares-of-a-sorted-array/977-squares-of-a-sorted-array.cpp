class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=-2;
        int j=-2;
        for(int k=0;k<nums.size();k++){
            if(nums[k]>=0){
                i=k;
                j=k-1;
                break;
            }
        }
        if(j==-2){
            j=nums.size()-1;
            i=nums.size();
        }
        vector<int>vec;
        while(i<nums.size() && j>=0){
            if(nums[i]<abs(nums[j])){
                vec.push_back(nums[i]*nums[i]);
                i++;
            }
            else{
                vec.push_back(nums[j]*nums[j]);
                j--;
            }
        }
        
        while(i<nums.size()){
            vec.push_back(nums[i]*nums[i]);
            i++;
        }
        while(j>=0){
            vec.push_back(nums[j]*nums[j]);
            j--;
        }
        return vec;
    }
};