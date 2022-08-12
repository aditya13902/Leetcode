class Solution {
public:
    unordered_map<int,int>mp;
    int helper(vector<int>&nums,int i){
        if(i>=nums.size()-1) return 0;
        if(mp.find(i)!=mp.end()) return mp[i];
        int ans=1e8;
        for(int j=i+1;j<=i+nums[i];j++){
            ans=min(ans,1+helper(nums,j));
        }
        return mp[i]=ans;
    }
    int jump(vector<int>& nums) {
        return helper(nums,0)!=1e8?helper(nums,0):-1;
    }
};