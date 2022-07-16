class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&cuts,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i;k<=j;k++){
            mini=min(mini,cuts[j+1]-cuts[i-1]+solve(cuts,i,k-1)+solve(cuts,k+1,j));
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        dp.resize(cuts.size(),vector<int>(cuts.size(),-1));
        return solve(cuts,1,cuts.size()-2);
        
    }
};