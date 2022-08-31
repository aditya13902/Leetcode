class Solution {
public:
    bool issafe(vector<vector<int>>&grid,int x,int y){
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()){
            return false;
        }
        if(grid[x][y]==1) return true;
        return false;
        
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int t=0;
        queue<vector<int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(q.size()){
            int len=q.size();
            // cout<<len<<endl;
            while(len--){
                auto curr=q.front();
                q.pop();
                int x=curr[0];
                int y=curr[1];
                // grid[x][y]=2;
                if(issafe(grid,x+1,y)){
                    q.push({x+1,y});
                    grid[x+1][y]=2;
                }
                if(issafe(grid,x-1,y)){
                    q.push({x-1,y});
                    grid[x-1][y]=2;
                }
                if(issafe(grid,x,y+1)){
                    q.push({x,y+1});
                    grid[x][y+1]=2;
                }
                if(issafe(grid,x,y-1)){
                    q.push({x,y-1});
                    grid[x][y-1]=2;
                }
            }
            if(q.size()){
                // cout<<q.size()<<endl;
                t++;
            }
            
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    // cout<<i<<" "<<j<<endl;
                    return -1;
                }
            }
        }
        return t;
    }
};
// [[2,2]
// ,[1,1]
// ,[0,0]
// ,[2,0]]