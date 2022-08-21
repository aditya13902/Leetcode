class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mx=-1;
        int cnt=0;
        for(auto ele:nums){
            if(cnt==0){
                mx=ele;
                cnt=1;
            }
            else if(ele==mx){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return mx;
    }
};