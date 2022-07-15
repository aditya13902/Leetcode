class Solution {
public:
    bool check(vector<int>&nums,int threshold,int m){
        int cnt=0;
        for(auto ele:nums){
            cnt+=ele/m;
            if(ele%m) cnt++;
        }
        return cnt<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=1;
        for(auto ele:nums) e=max(e,ele);
        int ans=-1;
        while(s<=e){
            int m=(s+e)/2;
            if(check(nums,threshold,m)){
                ans=m;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return ans;
    }
};