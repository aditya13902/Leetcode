class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0;
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
                if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size()){
                    continue;
                }
                if(grid[x][y]==-1 || grid[x][y]==0){
                    continue;
                }
                grid[x][y]=-1;
                q.push({x+1,y});
                q.push({x-1,y});
                q.push({x,y+1});
                q.push({x,y-1});
            }
            if(q.size()){
                time++;
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
        return time==0?0:time-1;
    }
};