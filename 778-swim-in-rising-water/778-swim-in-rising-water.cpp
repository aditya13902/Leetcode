class Solution {
public:
    int n;    
    bool dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, int maxtime){
        // if value exceed the max value (m) then that means no possible solution from the current path
        if(grid[i][j]>maxtime)
            return false;
        
        //dfs
        if(i==n-1 and j==n-1){
            return true;
        }
        
        visited[i][j] = true;
        
        int row[4] = {0,-1,0,1};
        int col[4] = {-1,0,1,0};
    
        for(int k=0;k<4;k++){
            if(i+row[k]>=0 and i+row[k]<n and j+col[k]>=0 and j+col[k]<n and !visited[i+row[k]][j+col[k]]){
                if(dfs(grid, i+row[k], j+col[k], visited, maxtime))
                    return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        // we need to minimize the maximum value for all the paths from top left to bottom right in grid
        int time=INT_MAX;
        n=grid.size();
        
        int l=0, h=n*n-1;
        while(l<=h){
            int m = l+(h-l)/2;
            vector<vector<bool>> visited(n, vector<bool>(n,false)); // every time we refill the vector
            
            // we one by one take upper limit to be m (maximum height allowed)
            if(dfs(grid, 0, 0, visited, m))
            { 
                // check whether there is a path to bottom right such that the max value is m
                // if present then we update our answer and try for some lesser values
                h=m-1;
                time = m;
            }
            else
            {
                // if not then on every value less it will fail so we try for bigger values
                l=m+1;
            }
        }
        
        return time;
    }
};