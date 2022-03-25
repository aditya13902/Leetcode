class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int helper(vector<vector<int>>& costs,int idx,int cnt){
        if(idx>=2*n){
            return 0;
        }
        if(dp[idx][cnt]!=-1){
            return dp[idx][cnt];
        }
        if(idx-cnt==n){
            return dp[idx][cnt]=costs[idx][0]+helper(costs,idx+1,cnt+1);
        }
        if(cnt>=n){
            return dp[idx][cnt]=costs[idx][1]+helper(costs,idx+1,cnt);
        }
        else{
            return dp[idx][cnt]=min(costs[idx][1]+helper(costs,idx+1,cnt),costs[idx][0]+helper(costs,idx+1,cnt+1));
        }
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        n=(costs.size())/2;
        dp.resize(2*n,vector<int>(n+1,-1));
        return helper(costs,0,0);
        
    }
};