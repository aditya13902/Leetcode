class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>&mat,int r, int c, int col) 
    {
        if(mat.empty())
        {
            return {};
        }
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        q.push({r,c});
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        vector<vector<int>>ans=mat;
        int t=mat[r][c];
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            vis[x][y]=true;
            bool count=false;
            for(auto it:dir)
            {
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&mat[nx][ny]==t)
                {
                    
                    if(vis[nx][ny]==false)
                    q.push({nx,ny});
                }
                else
                {
                    count=true;
                }
            }
            if(count)
            {
                ans[x][y]=col;
            }
           
        }
      
        return ans;
    }
};