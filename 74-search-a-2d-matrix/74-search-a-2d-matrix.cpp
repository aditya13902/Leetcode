class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row=mat.size();
        if(row==0){
            return false;
        }
        int col=mat[0].size();
        int r1=0;
        int r2=row-1;
        while(r1<r2){
            int mid=r1+(r2-r1)/2;
            if(mat[mid][col-1]<target){
                r1=mid+1;
            }
            else if(mat[mid][0]>target){
                r2=mid-1;
            }
            else{
                r1=mid;
                break;
            }
        }
        int c1=0;
        int c2=col-1;
        while(c1<=c2){
            int mid=c1+(c2-c1)/2;
            if(mat[r1][mid]<target){
                c1=mid+1;
            }
            else if(mat[r1][mid]>target){
                c2=mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};