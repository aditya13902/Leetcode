class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int>mpx;
        unordered_map<int,int>mpy;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    mpx[i]=1;
                    mpy[j]=1;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(mpx[i]){
                    matrix[i][j]=0;
                }
                if(mpy[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};