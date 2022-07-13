class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]-k]>0){
                cnt+=1;
                mp[nums[i]-k]=INT_MIN;
            }
            mp[nums[i]]++;
            
        }
        return cnt;
    }
};