class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int mx=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                mx=nums[i];
                cnt++;
            }
            else if(nums[i]==mx){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return mx;
    }
};