class Solution {
public:
    bool flag(vector<int>&nums,int m,int sum){
        int curr=0;
        int cnt=0;
        for(auto ele:nums){
            if(ele+curr>sum){
                curr=ele;
                cnt++;
            }
            else{
                curr+=ele;
            }
        }
        cnt++;
        return cnt<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int e=0;
        int s=0;
        for(auto ele:nums){
            e+=ele;
            s=max(ele,s);
        }
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(flag(nums,m,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
        
        
    }
};