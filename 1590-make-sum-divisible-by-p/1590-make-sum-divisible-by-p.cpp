class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int rem=0;
        for(auto ele:nums){
            rem=(rem+ele)%p;
        }
        if(rem==0) return 0;
        int curr=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int res=INT_MAX;
        for(int i=0;i<nums.size();i++){
            curr=(curr+nums[i])%p;
            mp[curr]=i;
            int mod=(curr-rem+p)%p;
            if(mp.find(mod)!=mp.end()){
                res=min(res,i-mp[mod]);
            }
        }
        if(res>=nums.size()) return -1;
        return res;
    }
};
// rem=4
// 0 3 4 8 10
// 0 3 4 2 4