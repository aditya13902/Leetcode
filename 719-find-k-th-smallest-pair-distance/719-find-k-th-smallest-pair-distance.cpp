class Solution {
public:
    bool check(int mid,vector<int> &nums,int k){
      int total=0;
      int j=0,n=nums.size();
      for(int i=0;i<n;i++){
        while(j<n && nums[j]-nums[i]<=mid)j++;
        j--;
        total+=(j-i);
      }
      return total>=k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int s=0;
        int e=nums[nums.size()-1]-nums[0];
        int ans=-1;
        while(s<=e){
            int m=(s+e)/2;
            if(check(m,nums,k)){
                ans=m;
                e=m-1;
            }
            else s=m+1;
        }
        return ans;
    }
};