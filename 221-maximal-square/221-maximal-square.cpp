class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>prev(m,0);
        int ans=0;
        for(int c=0;c<m;c++){
            if(matrix[0][c]=='1'){
                prev[c]=1;
                ans=1;
            }
        }
        
        for(int i=1;i<n;i++){
            vector<int>curr(m,0);
            if(matrix[i][0]=='1'){
                curr[0]=1;
                ans=max(ans,curr[0]);
            }
            for(int j=1;j<m;j++){
                int res=min({prev[j],curr[j-1],prev[j-1]});
                // int curr=0;
                if(matrix[i][j]=='1'){
                    curr[j]=1+res;
                }
                ans=max(ans,curr[j]);
            }
            prev=curr;
            
        }
        return ans*ans;
    }
};