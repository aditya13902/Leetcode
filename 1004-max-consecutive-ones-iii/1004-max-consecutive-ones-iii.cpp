class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int>vec;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                vec.push_back(i);
            }
        }
        int l=0;
        int cnt=0;
        int idx=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(cnt==k){
                    idx=vec[l]+1;
                    l++;
                }
                else{
                    cnt++;
                }
            }
            ans=max(ans,i-idx+1);
        }
        return ans;
        
        
    }
};