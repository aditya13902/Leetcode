class Solution {
public:
    vector<bool>vis;
    void dfs(vector<vector<int>>& rooms,int idx){
        if(vis[idx]){
            return;
        }
        vis[idx]=true;
        for(auto ele:rooms[idx]){
            dfs(rooms,ele);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vis.resize(rooms.size(),false);
        dfs(rooms,0);
        for(int i=0;i<rooms.size();i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};