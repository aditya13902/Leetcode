class Solution {
public:
    bool safe(vector<vector<int>>& grid,int& r,int &c){
        if(grid[r][c]==1){
            if(c==grid[0].size()-1 || grid[r][c+1]==-1){
                return false;
            }
        }
        else{
            if(c==0 || grid[r][c-1]==1){
                return false;
            }
        }
        return true;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans(grid[0].size(),-1);
        for(int i=0;i<grid[0].size();i++){
            int r=0;
            int c=i;
            int f=1;
            while(r!=grid.size()){
                if(!safe(grid,r,c)){
                    f=0;
                    break;
                }
                if(grid[r][c]==1){
                    r++;
                    c++;
                }
                else{
                    r++;
                    c--;
                }
            }
            if(f){
                ans[i]=c;
            }else{
                continue;
            }
        }
        return ans;
    }
};