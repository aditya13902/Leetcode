class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,int>>q;
        int row=maze.size();
        int col=maze[0].size();
        q.push({entrance[0],entrance[1]});
        map<pair<int,int>,int>mp;
        if(entrance[0]-1<0){
            mp[{entrance[0]-1,entrance[1]}]=1;
        }
        if(entrance[0]+1>=row){
            mp[{entrance[0]+1,entrance[1]}]=1;
        }
        if(entrance[1]-1<0){
            mp[{entrance[0],entrance[1]-1}]=1;
        }
        if(entrance[1]+1>=col){
            mp[{entrance[0],entrance[1]+1}]=1;
        }
        int d=-1;
        // int ans=
        while(q.size()){
            int l=q.size();
            while(l--){
                auto [x,y]=q.front();
                q.pop();
                if(mp[{x,y}]){
                    continue;
                }
                if(x<0 || x>=row || y<0 ||y>=col){
                    return d;
                }
                if(maze[x][y]!='.'){
                    continue;
                }
                maze[x][y]='+';
                q.push({x-1,y});
                q.push({x+1,y});
                q.push({x,y-1});
                q.push({x,y+1});
            }
            if(q.size()){
                d++;
            }
        }
        return -1;
    }
};