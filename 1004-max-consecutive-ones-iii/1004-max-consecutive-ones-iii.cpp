class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int cnt=0;
        int ans=0;
        while(j<nums.size()){
            
            if(nums[j]==1){
                j++;
            }
            else{
                j++;
                cnt++;
                while(cnt>k){
                    if(nums[i]==0){
                        cnt--;
                    }
                    i++;
                }
            }
            ans=max(ans,j-i);
            
        }
        return ans;
    }
};