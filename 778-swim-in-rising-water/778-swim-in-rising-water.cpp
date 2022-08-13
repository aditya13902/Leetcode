class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        set<pair<int,int>>vis;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({grid[0][0],0,0});
        while(pq.size()){
            auto curr=pq.top();
            pq.pop();
            int mx=curr[0];
            int x=curr[1];
            int y=curr[2];
            if(vis.find({x,y})!=vis.end()) continue;
            vis.insert({x,y});
            // mx=max(mx,grid[i][j]);
            if(x==n-1 && y==n-1) return max(mx,grid[x][y]);
            
            if(x-1>=0) pq.push({max(mx,grid[x-1][y]),x-1,y});
            if(y-1>=0) pq.push({max(mx,grid[x][y-1]),x,y-1});
            if(x+1<n) pq.push({max(mx,grid[x+1][y]),x+1,y});
            if(y+1<n) pq.push({max(mx,grid[x][y+1]),x,y+1});
            
        }
        return -1;
    }
};