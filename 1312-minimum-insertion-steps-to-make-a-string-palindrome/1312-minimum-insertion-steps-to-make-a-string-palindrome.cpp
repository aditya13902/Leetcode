class Solution {
public:
    int minInsertions(string str) {
        int n=str.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        for(int l=1;l<n;l++){
            for(int i=0;i<n-l;i++){
                int j=i+l;
                if(str[i]==str[j]){
                    if(i==j-1){
                        dp[i][j]=0;
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                else{
                    dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
                }
            }     
        }
        return dp[0][n-1];
    }
};
// mbadm
// // mdabm
//     int n=str.size();
//     vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
//     for(int i=0;i<n;i++){
//         dp[i][i]=0;
//     }
//     for(int l=1;l<n;l++){
//         for(int i=0;i<n-l;i++){
//             int j=i+l;
//             if(str[i]==str[j]){
//                 if(i==j-1){
//                     dp[i][j]=0;
//                 }
//                 else{
//                     dp[i][j]=dp[i+1][j-1];
//                 }
//             }
//             else{
//                 dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
//             }
//         }     
//     }
//     return dp[0][n-1];