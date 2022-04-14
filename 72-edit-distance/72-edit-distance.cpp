class Solution {
public:
    vector<vector<int>>dp;
    int helper(string A,string B,int i,int j){
        if(i>=A.size() || j>=B.size()){
            return max(A.size()-i,B.size()-j);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(A[i]==B[j]){
            return dp[i][j]=helper(A,B,i+1,j+1);
        }
        else{
            return dp[i][j]=1+min(helper(A,B,i+1,j+1),min(helper(A,B,i+1,j),helper(A,B,i,j+1)));
        }
    }
    int minDistance(string A, string B) {
        dp.resize(A.size(),vector<int>(B.size(),-1));
        return helper(A,B,0,0);
    }
};