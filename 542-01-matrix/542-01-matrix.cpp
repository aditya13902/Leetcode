class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else{
                    mat[i][j]=-1;
                }
            }
        }
        int d=0;
        while(q.size()){
            int l=q.size();
            d++;
            while(l--){
                auto top=q.front();
                q.pop();
                int r=top.first;
                int c=top.second;
                if(r+1<mat.size() && mat[r+1][c]==-1){
                    mat[r+1][c]=d;
                    q.push({r+1,c});
                }
                if(r-1>=0 && mat[r-1][c]==-1){
                    mat[r-1][c]=d;
                    q.push({r-1,c});
                }
                if(c-1>=0 && mat[r][c-1]==-1){
                    mat[r][c-1]=d;
                    q.push({r,c-1});
                }
                if(c+1<mat[0].size() && mat[r][c+1]==-1){
                    mat[r][c+1]=d;
                    q.push({r,c+1});
                }
            }
        }
        return mat;
    }
};