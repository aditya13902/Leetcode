class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int m=l+(r-l)/2;
            // cout<<m<<endl;
            int f1=m>0?nums[m-1]==nums[m]:0;
            int f2=m<nums.size()-1?nums[m+1]==nums[m]:0;
            if(!f1 && !f2){
                return nums[m];
            }
            else if(f1){
                if(m%2){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
            else{
                if(m%2){
                    r=m-1;
                }
                else{
                    l=m+1;
                }
            }
        }
        return -1;
    }
};