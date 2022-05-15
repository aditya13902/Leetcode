class Solution {
public:
    vector<vector<int>>dp;
    int helper(vector<int>& cuts,int i,int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int mi=INT_MAX;
        for(int idx=i;idx<=j;idx++){
            int ans=cuts[j+1]-cuts[i-1]+helper(cuts,i,idx-1)+helper(cuts,idx+1,j);
            mi=min(mi,ans);
        }
        return dp[i][j]=mi;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        dp.resize(cuts.size(),vector<int>(cuts.size(),-1));
        return helper(cuts,1,cuts.size()-2);
        
    }
};