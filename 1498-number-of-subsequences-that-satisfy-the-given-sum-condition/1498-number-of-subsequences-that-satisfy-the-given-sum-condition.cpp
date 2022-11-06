class Solution {
public:
    const int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        vector<int>pow2={1};
        for(int i=pow2.size();i<=nums.size();i++){
            pow2.push_back((pow2.back()*2)%mod);
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int ans=0;
        while(i<=j){
            if(nums[i]+nums[j]<=target){
                ans=(ans+pow2[j-i])%mod;
                i++;
            }
            else{
                j--;
            }
        }
        
        
        return ans;
    }
};