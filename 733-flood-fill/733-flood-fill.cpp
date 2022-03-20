class Solution {
public:
    int color;
    void helper(vector<vector<int>>& image, int sr, int sc, int newColor){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=color || image[sr][sc]==newColor){
            return;
        }
        image[sr][sc]=newColor;
        helper(image,sr+1,sc,newColor);
        helper(image,sr,sc+1,newColor);
        helper(image,sr,sc-1,newColor);
        helper(image,sr-1,sc,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        color=image[sr][sc];
        helper(image,sr,sc,newColor);
        return image;
    }
};