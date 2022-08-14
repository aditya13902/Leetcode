class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>&cuts,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mn=1e9;
        for(int k=i;k<=j;k++){
            mn=min(mn,cuts[j+1]-cuts[i-1]+helper(cuts,i,k-1)+helper(cuts,k+1,j));
        }
        return dp[i][j]=mn;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int siz=cuts.size();
        dp.resize(siz+1,vector<int>(siz+1,-1));
        return helper(cuts,1,cuts.size()-2);
    }
};