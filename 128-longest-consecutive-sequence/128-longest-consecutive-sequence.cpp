class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto ele:nums){
            mp[ele]=1;
        }
        int ans=0;
        for(auto ele:nums){
            if(mp[ele+1]==0){
                int curr=ele;
                int cnt=0;
                while(mp[curr]){
                    cnt++;
                    curr--;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};