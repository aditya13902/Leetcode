class Solution {
public:
    vector<vector<vector<int>>>dp;
    int helper(vector<int>& arr,int mx,int idx,int d){
        if(d<0){
            return 1e9;
        }
        if(idx==arr.size()){
            if(d==0){
                return mx;
            }
            else{
                return 1e9;
            }
        }
        if(dp[idx][d][mx]!=-1) return dp[idx][d][mx];
        int ans=mx+helper(arr,arr[idx],idx+1,d-1);
        ans=min(ans,helper(arr,max(arr[idx],mx),idx+1,d));
        return dp[idx][d][mx]=ans;
    }
    int minDifficulty(vector<int>& diff, int d) {
        dp.resize(diff.size(),vector<vector<int>>(d,vector<int>(1005,-1)));
        int ans=helper(diff,diff[0],1,d-1);
        return ans==1e9?-1:ans;
    }
};
// 1 1 1 7 7 7 