class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num=-1;
        int cnt=0;
        for(auto ele:nums){
            if(ele==num){
                cnt++;
            }
            else if(cnt==0){
                num=ele;
                cnt=1;
            }
            else{
                cnt--;
            }
        }
        cnt=0;
        for(auto ele:nums){
            if(ele==num) cnt++;
        }
        if(cnt>(nums.size()/2)) return num;
        return -1;
    }
};