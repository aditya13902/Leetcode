class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int j=matrix[0].size();
        int l=0;
        int r=n*j-1;
        while(l<=r){
            int m=l+(r-l)/2;
            int curr_r=m/j;
            int curr_c=m%j;
            if(matrix[curr_r][curr_c]==target) return true;
            else if(matrix[curr_r][curr_c]<target) l=m+1;
            else r=m-1;
        }
        return false;
    }
};