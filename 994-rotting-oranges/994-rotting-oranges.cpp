class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int t=0;
        while(q.size()){
            int l=q.size();
            while(l--){
                auto top=q.front();
                q.pop();
                int r=top.first;
                int c=top.second;
                if(r+1<grid.size() && grid[r+1][c]==1){
                    grid[r+1][c]=2;
                    q.push({r+1,c});
                }
                if(r-1>=0 && grid[r-1][c]==1){
                    grid[r-1][c]=2;
                    q.push({r-1,c});
                }
                if(c-1>=0 && grid[r][c-1]==1){
                    grid[r][c-1]=2;
                    q.push({r,c-1});
                }
                if(c+1<grid[0].size() && grid[r][c+1]==1){
                    grid[r][c+1]=2;
                    q.push({r,c+1});
                }
                
            }
            if(q.size()){
                t++;
            }
            // t++;
            
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return t;
    }
};