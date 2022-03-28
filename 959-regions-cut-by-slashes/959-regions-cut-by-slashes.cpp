class Solution {
    vector<vector<vector<bool>>>vis;
    int h;
    int w;
    vector<string>mat;
    void dfs(int row,int col,int type){
        if((row<0 || col<0 || row>=h || col>=w) || vis[row][col][type]){
            return;
        }
        vis[row][col][type]=true;
        if(type==0){
            dfs(row-1,col,2);
        }
        else if(type==1){
            dfs(row,col+1,3);
        }
        else if(type==2){
            dfs(row+1,col,0);
        }
        else{
            dfs(row,col-1,1);
        }
        
        if(mat[row][col]!='/'){
            dfs(row,col,type ^ 1);
        }
        if(mat[row][col]!='\\'){
            dfs(row,col,type ^ 3);
        }
           
    }
public:
    
    int regionsBySlashes(vector<string>& grid) {
        h=grid.size();
        w=grid[0].size();
        mat=grid;
        vis.resize(h,vector<vector<bool>>(w,vector<bool>(4,false)));
        int cnt=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                for(int r=0;r<4;r++){
                    if(!vis[i][j][r]){
                        dfs(i,j,r);
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};