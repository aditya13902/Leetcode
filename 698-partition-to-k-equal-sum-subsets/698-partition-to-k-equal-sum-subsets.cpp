class Solution {
public:
    int div;
    bool helper(vector<int>&nums,int sum,int k,int idx,vector<int>&vis){
        if(k==0){
            return true;
        }
        if(sum==div){
            return helper(nums,0,k-1,0,vis);
        }
        int f=0;
        for(int i=idx;i<nums.size();i++){
            if(vis[i] || sum+nums[i]>div || (i>0 && nums[i]==nums[i-1] && !vis[i-1])) continue;
            vis[i]=true;
            if(helper(nums,sum+nums[i],k,i+1,vis)) return true;
            vis[i]=false;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(auto ele:nums) sum+=ele;
        
        if(nums.size()<k || sum%k) return false;
        vector<int>vis(nums.size(),false);
        
        div=sum/k;
        sort(nums.begin(),nums.end(),greater<int>());
        return helper(nums,0,k,0,vis);
    }
};