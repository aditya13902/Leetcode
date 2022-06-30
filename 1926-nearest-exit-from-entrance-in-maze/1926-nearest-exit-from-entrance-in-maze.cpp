class Solution {
public:
    int r,c;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        r=maze.size();
        c=maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        // maze[entrance[0]][entrance[1]]='+';
        int d=0;
        int px=entrance[0];
        int py=entrance[1];
        while(q.size()){
            int l=q.size();
            while(l--){
                auto [x,y]=q.front();
                q.pop();
                if(maze[x][y]=='+'){
                    continue;
                }
                if(!(x==px && y==py) && (x==0 || x==r-1 ||y==0 ||y==c-1)){
                    return d;
                }
                maze[x][y]='+';
                if(x-1>=0){
                    q.push({x-1,y});
                }
                if(x+1<r){
                    q.push({x+1,y});
                }
                if(y-1>=0){
                    q.push({x,y-1});
                }
                if(y+1<c){
                    q.push({x,y+1});
                }
                
            }
            d++;
        }
        return -1;
        
    }
};