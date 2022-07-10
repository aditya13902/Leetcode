class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        // vector<vector<int>>dp(r,vector<int>(c,0));
        int cnt=0;
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         if(matrix[i][j]==1){
        //             dp[i][j]=1;
        //         }
        //     }
        // }
        vector<int>prev(c);
        for(int i=0;i<c;i++){
            if(matrix[r-1][i]){
                prev[i]=1;
                cnt++;
            }
        }
        int ans=0;
        for(int i=r-2;i>=0;i--){
            vector<int>curr(c);
            if(matrix[i][c-1]){
                curr[c-1]=1;
                cnt++;
            }
            for(int j=c-2;j>=0;j--){
                if(matrix[i][j]){
                    curr[j]=1+min({prev[j+1],prev[j],curr[j+1]});
                    
                }
                else{
                    curr[j]=0;
                }
                cnt+=curr[j];
            }
            prev=curr;
        }

        return cnt;
    }
};