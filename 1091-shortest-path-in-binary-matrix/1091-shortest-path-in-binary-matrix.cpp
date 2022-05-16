class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        q.push({0,0});
        int dx[8]={0,1,1,-1,0,-1,1,-1};
        int dy[8]={1,0,1,0,-1,-1,-1,1};
        int cnt=0;
        // map<pair<int,int>,int>mp;
        while(q.size()){
            int l=q.size();
            while(l--){
                auto top=q.front();
                q.pop();
                if(grid[top.first][top.second]!=0){
                    continue;
                }
                if(top.first==grid.size()-1 && top.second==grid[0].size()-1){
                    return ++cnt;
                }
                grid[top.first][top.second]=1;
                for(int i=0;i<8;i++){
                    int x=top.first+dx[i];
                    int y=top.second+dy[i];
                    if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size()){
                        q.push({x,y});
                    }
                    
                }
            }
            cnt++;
        }
        return -1;
    }
};