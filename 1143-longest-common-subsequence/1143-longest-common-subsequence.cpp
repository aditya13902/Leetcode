class Solution {
private:
    vector<vector<int>>dp;
    int helper(string &str1,string &str2,int i,int j){
        if(i>=str1.size() || j>=str2.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(str1[i]==str2[j]){
            return dp[i][j]=1+helper(str1,str2,i+1,j+1);
        }
        else{
            return dp[i][j]=max(helper(str1,str2,i,j+1),helper(str1,str2,i+1,j));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(),vector<int>(text2.size(),-1));
        return helper(text1,text2,0,0);
    }
};