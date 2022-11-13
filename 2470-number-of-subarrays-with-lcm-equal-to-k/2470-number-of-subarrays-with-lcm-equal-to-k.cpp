class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            if(curr==k) cnt++;
            if(curr>k) continue;
            for(int j=i+1;j<nums.size();j++){
                int lcm=((curr*nums[j])/__gcd(curr,nums[j]));
                if(lcm==k) cnt++;
                if(lcm>k) break;
                curr=lcm;
            }
        }
        return cnt;
    }
};