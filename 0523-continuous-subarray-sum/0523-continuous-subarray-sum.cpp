class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int i=0;
        for(auto ele:nums){
            sum=(sum+ele)%k;
            if(mp.find(sum)!=mp.end()){
                if(i-mp[sum]>=2){
                    return true;
                }
            }
            else{
                mp[sum]=i;    
            }
            i++;
        }
        return false;
    }
};