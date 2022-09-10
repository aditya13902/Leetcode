class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        int sum=0;
        for(auto ele:nums){
            sum=(sum+ele)%p;
        }
        if(sum==0) return 0;
        int find=(sum%p);
        int curr=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            curr=(curr+nums[i])%p;
            mp[curr]=i;
            int mod=(curr-find+p)%p;
            if(mp.find(mod)!=mp.end()){
                ans=min(ans,i-mp[mod]);
            }
        }
        if(ans==INT_MAX || ans==n) return -1;
        return ans;
    }
};