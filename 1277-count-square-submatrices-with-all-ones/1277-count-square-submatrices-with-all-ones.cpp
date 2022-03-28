class Solution {
private:
    int row;
    int col;
    
public:
    int countSquares(vector<vector<int>>& mat) {
        // mat=matrix;
        row=mat.size();
        col=mat[0].size();
        int cnt=0;
        // dp.resize(row+1,vector<int>(col+1,-1));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==1){
                    if(i==0 || j==0){
                        cnt+=1;
                    }
                    else{
                        int sub=1+min(mat[i-1][j],min(mat[i][j-1],mat[i-1][j-1]));
                        cnt+=sub;
                        mat[i][j]=sub; 
                    }
                }
            }
        }
        return cnt;
    }
};