class Solution {
public:
    int cnt=0;
    vector<vector<int>>moves={{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>>vis;
    bool helper(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j){
        if(i<0 || j<0 || i>=grid2.size() ||j>=grid2[0].size() || grid2[i][j]==0 || vis[i][j]){
            return true;
        }
        if(grid1[i][j]==0){
            return false;
        }
        vis[i][j]=1;
        bool res=true;
        for(int k=0;k<4;k++){
            res&=helper(grid1,grid2,i+moves[k][0],j+moves[k][1]);
        }
        return res;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vis.resize(grid2.size(),vector<int>(grid2[0].size(),0));
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                if(grid2[i][j]==1 && vis[i][j]==0){
                    if(helper(grid1,grid2,i,j)){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};