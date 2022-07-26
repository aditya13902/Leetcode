class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        q.push({sr,sc});
        int curr=image[sr][sc];
        while(q.size()){
            auto [r,c]=q.front();
            q.pop();
            if(r<0 || c<0 || r>=image.size() || c>=image[0].size() || image[r][c]!=curr || image[r][c]==color) continue;
            
            image[r][c]=color;
            q.push({r+1,c});
            q.push({r-1,c});
            q.push({r,c+1});
            q.push({r,c-1});
        }
        return image;
    }
};