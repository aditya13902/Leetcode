class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        int zerorow=0;
        int zerocol=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    if(i==0){
                        zerorow=1;
                    }
                    if(j==0){
                        zerocol=1;
                    }
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][0]==0){
                    matrix[i][j]=0;
                }
                if(matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(zerorow){
            for(int i=0;i<c;i++){
                matrix[0][i]=0;
            }
        }
        if(zerocol){
            for(int i=0;i<r;i++){
                matrix[i][0]=0;
            }
        }
    }
};
