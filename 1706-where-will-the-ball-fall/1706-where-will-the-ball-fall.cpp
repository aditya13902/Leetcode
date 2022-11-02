class Solution {
public:
    int row;
    int col;
    int helper(vector<vector<int>>&grid,int i,int j){
        if(i==row) return j;
        if(grid[i][j]==1){
            if(j+1<col && grid[i][j+1]==1){
                return helper(grid,i+1,j+1);
            }
            else{
                return -1;
            }
        }
        else{
            if(j-1>=0 && grid[i][j-1]==-1){
                return helper(grid,i+1,j-1);
            }
            else return -1;
        }
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        vector<int>ans(grid[0].size());
        for(int c=0;c<col;c++){
            ans[c]=helper(grid,0,c);
        }
        return ans;
    }
};