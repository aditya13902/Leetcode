class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0;
        int j=n*m-1;
        while(i<=j){
            int curr=i+(j-i)/2;
            int r=(curr/m);
            int c=(curr%m);
            if(matrix[r][c]==target) return true;
            else if(matrix[r][c]<target){
                i=curr+1;
            }
            else{
                j=curr-1;
            }
        }
        return false;
    }
};