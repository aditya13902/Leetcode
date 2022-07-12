class Solution {
public:
    int dp[101][101];
    bool dfs(string &s, int i, int open) {
        if (open < 0) return 0;
        if (i == s.length()) return open == 0;
        if (dp[i][open] != -1) return dp[i][open];
        if (s[i] == '(') return dp[i][open] = dfs(s, i + 1, open + 1);
        if (s[i] == ')') return dp[i][open] = dfs(s, i + 1, open - 1);      
        return dp[i][open] = dfs(s, i + 1, open + 1) || dfs(s, i + 1, open - 1) || dfs(s, i + 1, open);
    }
    
    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, 0);
    }
};