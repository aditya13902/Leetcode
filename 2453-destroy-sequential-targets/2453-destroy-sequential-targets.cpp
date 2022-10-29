class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        vector<int>mod(nums.size());
        for(int i=0;i<nums.size();i++){
            mod[i]=nums[i]%space;
            // cout<<mod[i]<<" ";
        }
        unordered_map<int,int>mp;
        int mx=0;
        int ans=INT_MAX;
        for(int i=0;i<mod.size();i++){
            mp[mod[i]]++;
            mx=max(mx,mp[mod[i]]);
        }
        for(int i=0;i<mod.size();i++){
            if(mx==mp[mod[i]]){
                ans=min(ans,nums[i]);
            }
        }
        return ans;
    }
};