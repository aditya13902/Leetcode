class Solution {
public:
    void fill(vector<vector<int>>& image, int i, int j, int color,int prev){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=prev || image[i][j]==color){
            return;
        }
        image[i][j]=color;
        fill(image,i+1,j,color,prev);
        fill(image,i,j-1,color,prev);
        fill(image,i-1,j,color,prev);
        fill(image,i,j+1,color,prev);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int curr=image[sr][sc];
        fill(image,sr,sc,color,curr);
        return image;
    }
};