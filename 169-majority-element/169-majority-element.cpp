class Solution {
public:
    int f=0;
    int ans=0;
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto ele:nums){
            mp[ele]++;
            if(mp[ele]>f){
                ans=ele;
                f=mp[ele];
            }
        }
        return ans;
    }
};