class Solution {
public:
    vector<vector<int>>dp;
    int helper(string& word1,string& word2,int i,int j){
        if(i==word1.size() && j==word2.size()) return 0;
        if(i==word1.size() || j==word2.size()) return i==word1.size()?word2.size()-j:word1.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=helper(word1,word2,i+1,j+1);
        }
        else{
            return dp[i][j]=1+min({helper(word1,word2,i+1,j),helper(word1,word2,i,j+1),helper(word1,word2,i+1,j+1)});
        }
    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.size(),vector<int>(word2.size(),-1));
        return helper(word1,word2,0,0);
    }
};