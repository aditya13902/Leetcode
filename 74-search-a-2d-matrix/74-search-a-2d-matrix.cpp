class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row=0;
        int col=mat[0].size()-1;
        while(row<mat.size() && col>=0){
            if(mat[row][col]==target){
                return true;
            }
            else if(mat[row][col]<target){
                row++;
            }
            else{
                col--;
            }
        }
        return false;
    }
};