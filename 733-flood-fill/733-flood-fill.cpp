class Solution {
public:
    void dfs(vector<vector<int>>& image,int i,int j,int col,int pre){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size()){
            return;
        }
        if(image[i][j]==col || image[i][j]!=pre){
            return;
        }
        image[i][j]=col;
        dfs(image,i+1,j,col,pre);
        dfs(image,i-1,j,col,pre);
        dfs(image,i,j+1,col,pre);
        dfs(image,i,j-1,col,pre);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};