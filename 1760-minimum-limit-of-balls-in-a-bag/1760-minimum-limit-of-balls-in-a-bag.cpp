class Solution {
public:
    bool flag(vector<int>& nums, int mx,int m){
        
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=m){
                continue;
            }
            cnt+=((nums[i]/m)-1);
            if(nums[i]%m!=0){
                cnt++;
            }
        }
        // cout<<m<<"-->"<<cnt<<endl;
        return cnt<=mx;
    }
    int minimumSize(vector<int>& nums, int mx) {
        int s=1;
        int e=1;
        for(auto ele:nums){
            e=max(ele,e);
        }
        int ans=0;
        while(s<=e){
            int m=s+(e-s)/2;
            if(flag(nums,mx,m)){
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