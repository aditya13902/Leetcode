class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        int d=0;
        while(q.size()){
            int l=q.size();
            while(l--){
                auto curr=q.front();
                int x=curr.first;
                int y=curr.second;
                q.pop();
                // cout<<x<<" "<<y<<endl;
                if(x+1<n && dis[x+1][y]==-1){
                    dis[x+1][y]=d+1;
                    q.push({x+1,y});
                }
                if(x-1>=0 && dis[x-1][y]==-1){
                    dis[x-1][y]=d+1;
                    q.push({x-1,y});
                }
                if(y+1<m && dis[x][y+1]==-1){
                    dis[x][y+1]=d+1;
                    q.push({x,y+1});
                }
                if(y-1>=0 && dis[x][y-1]==-1){
                    dis[x][y-1]=d+1;
                    q.push({x,y-1});
                }
            }
            d++;
        }
        return dis;
    }
};