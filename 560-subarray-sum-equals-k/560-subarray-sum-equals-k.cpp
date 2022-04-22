class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        vector<int>prefix;
        for(int i=0;i<nums.size();i++){
            prefix.push_back(sum);
            sum+=nums[i];
        }
        prefix.push_back(sum);
        int ans=0;
        for(int i=0;i<prefix.size();i++){
            if(mp[prefix[i]-k]){
                ans+=mp[prefix[i]-k];
            }
            mp[prefix[i]]++;
        }
        return ans;
        
    }
};