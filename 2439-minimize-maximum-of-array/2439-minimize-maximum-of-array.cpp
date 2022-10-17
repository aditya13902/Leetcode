class Solution {
public:
    bool check(vector<long long>nums,long long val){
        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i]>val){
                nums[i-1]=nums[i-1]+(nums[i]-val);
                nums[i]=val;
            }
        }
        return nums[0]<=val;
    }
    int minimizeArrayValue(vector<int>& nums) {
        vector<long long>arr;
        for(auto ele:nums){
            arr.push_back((long long)ele);
        }
        long long l=0;
        long long r=*max_element(nums.begin(),nums.end());
        long long ans=-1;
        while(l<=r){
            long long m=l+((r-l)/2);
            if(check(arr,m)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};