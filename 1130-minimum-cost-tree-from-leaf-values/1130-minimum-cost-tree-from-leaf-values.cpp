class Solution {
public:
    vector<vector<int>>dp;
    int find(vector<int>&arr,int i,int j){
        int ans=0;
        for(int idx=i;idx<=j;idx++){
            ans=max(ans,arr[idx]);
        }
        return ans;
    }
    int helper(vector<int>&arr,int i,int j){
        if(i>=j) return 0;
        int ans=INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<j;k++){
            int lmax=find(arr,i,k);
            int rmax=find(arr,k+1,j);
            int lsum=helper(arr,i,k);
            int rsum=helper(arr,k+1,j);
            ans=min(ans,lmax*rmax+lsum+rsum);
        }
        return dp[i][j]=ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        dp.resize(arr.size(),vector<int>(arr.size(),-1));
        return helper(arr,0,arr.size()-1);
    }
};