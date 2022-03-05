class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        unordered_map<int,int>mp2;
        for(auto ele:mp[key]){
            if(ele<nums.size()-1){
                mp2[nums[ele+1]]++;
            }
        }
        int mx=0;
        int ans=0;
        for(auto it:mp2){
            if(mx<it.second){
                ans=it.first;
                mx=it.second;
            }
        }
        return ans;
    }
};