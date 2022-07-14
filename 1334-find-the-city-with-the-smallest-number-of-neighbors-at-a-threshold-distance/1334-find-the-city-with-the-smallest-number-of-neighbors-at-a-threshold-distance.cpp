class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        for(auto vec:edges){
            dp[vec[0]][vec[1]]=vec[2];
            dp[vec[1]][vec[0]]=vec[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dp[i][k]!=INT_MAX && dp[k][j]!=INT_MAX && dp[i][j]>dp[i][k]+dp[k][j]){
                        dp[i][j]=dp[i][k]+dp[k][j];
                    }
                }
            }
        }
        int ans=INT_MAX;
        int v=-1;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dp[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=ans){
                v=i;
                ans=cnt;
            }
        }
        return v;
    }
};