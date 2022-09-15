class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        int mx=1;
        for(auto num:nums){
            int cnt=0;
            while(num>0){
                if(num&1){
                    ans++;
                }
                cnt++;
                num=num>>1;
            }
            mx=max(mx,cnt);
        }
        return ans+mx-1;
    }
};