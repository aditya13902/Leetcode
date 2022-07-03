class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; ++i) dp[i][i] = 0;
        for (const auto &e : edges) {
            dp[e[0]][e[1]] = e[2];
            dp[e[1]][e[0]] = e[2];
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[i][j] > dp[i][k] + dp[k][j]) dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
        auto m = INT_MAX, res = -1;
        for (int i = n - 1; i >= 0; --i) {
            auto cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (dp[i][j] <= distanceThreshold) ++cnt;
            }
            if (cnt < m) {
                m = cnt;
                res = i;
            }
        }
        return res;
    }
};