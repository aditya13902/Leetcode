class Solution {
public:
    int solve(string& s, string& t, vector<vector<int>>& dp, int idxS, int idxT, const int& n, const int& m)
{
	if(idxT == m) return 1;
	if(idxS == n) return 0;

	if(dp[idxS][idxT] != -1) return dp[idxS][idxT];

	if(s[idxS] == t[idxT])
		return dp[idxS][idxT] = solve(s, t, dp, idxS+1, idxT+1, n, m) + solve(s, t, dp, idxS+1, idxT, n, m);


	return dp[idxS][idxT] = solve(s, t, dp, idxS+1, idxT, n, m);
}

int numDistinct(string s, string t) {
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
	return solve(s, t, dp, 0, 0, n, m);
}
};