class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0){
            return -1;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        int d=1;
        vector<int>dx={0,1,1,-1,0,-1,1,-1};
        vector<int>dy={1,0,1,0,-1,-1,-1,1};
        while(q.size()){
            int l=q.size();
            while(l--){
                auto node=q.front();
                int x=node.first;
                int y=node.second;
                q.pop();
                if(x==grid.size()-1 && y==grid[0].size()-1){
                    return d;
                }
                if(grid[x][y]==-1){
                    continue;
                }
                grid[x][y]=-1;
                for(int i=0;i<8;i++){
                    if(x+dx[i]>=0 && x+dx[i]<grid.size() && y+dy[i]>=0 && y+dy[i]<grid[0].size() && grid[x+dx[i]][y+dy[i]]==0){
                        q.push({x+dx[i],y+dy[i]});
                    }
                }
                
            }
            d++;
        }
        return -1;
    }
};