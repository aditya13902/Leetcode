class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
                
            }
        }
        int d=0;
        while(q.size()){
            int l=q.size();
            while(l--){
                auto top=q.front();
                int i=top.first;
                int j=top.second;
                q.pop();
                if(i+1<grid.size() && grid[i+1][j]==0){
                    grid[i+1][j]=1;
                    q.push({i+1,j});
                }
                if(i-1>=0 && grid[i-1][j]==0){
                    grid[i-1][j]=1;
                    q.push({i-1,j});
                }
                if(j+1<grid[0].size() && grid[i][j+1]==0){
                    grid[i][j+1]=1;
                    q.push({i,j+1});
                }
                if(j-1>=0 && grid[i][j-1]==0){
                    grid[i][j-1]=1;
                    q.push({i,j-1});
                }
            }
            if(q.size()){
                d++;
            }
            
        }
        return d==0?-1:d;
    }
};