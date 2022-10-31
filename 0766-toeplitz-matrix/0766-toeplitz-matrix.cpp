class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int row=0;row<matrix.size();row++){
            for(int col=0;col<matrix[0].size();col++){
                int i=row;
                int j=col;
                int f=1;
                while(i<matrix.size() && j<matrix[0].size()){
                    if(matrix[row][col]!=matrix[i++][j++]){
                        return false;
                    }   
                }
            }
        }
        
        return true;
    }
};
// [[36,59,71,15,26,82,87]
// ,[56,36,59,71,15,26,82]
// ,[15,0,36,59,71,15,26]]