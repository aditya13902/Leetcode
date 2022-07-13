class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        int cnt=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum=((sum+nums[i])%k+k)%k;
            cnt+=mp[sum];
            mp[sum]++;
        }
        // 0 4 9 9 7 4 5
        return cnt;
    }
};