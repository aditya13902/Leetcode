class Solution {
public:
    vector<vector<int>>dp;
    int helper(string A,string B,string C,int i,int j,int k){
        if(i==A.size() && j==B.size() && k==C.size()){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int res=false;
        if(i!=A.size() && A[i]==C[k]){
            res|=helper(A,B,C,i+1,j,k+1);
        }
        if(j!=B.size() && B[j]==C[k]){
            res|=helper(A,B,C,i,j+1,k+1);
        }
        return dp[i][j]=res;
    }
    bool isInterleave(string A, string B, string C) {
        dp.resize(A.size()+1,vector<int>(B.size()+1,-1));
        return helper(A,B,C,0,0,0);
    }
};