class Solution {
public:
    int n;
    int m;
    void dfs(vector<vector<int>>& heights,int i,int j,int prev,vector<vector<int>>&ocean){
        if(i<0 || i>=n || j<0 || j>=m || ocean[i][j] || prev>heights[i][j]) return;
        ocean[i][j]=1;
        dfs(heights,i+1,j,heights[i][j],ocean);
        dfs(heights,i-1,j,heights[i][j],ocean);
        dfs(heights,i,j+1,heights[i][j],ocean);
        dfs(heights,i,j-1,heights[i][j],ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dfs(heights,i,0,INT_MIN,pacific);
            dfs(heights,i,m-1,INT_MIN,atlantic);
        }
        for(int j=0;j<m;j++){
            dfs(heights,0,j,INT_MIN,pacific);
            dfs(heights,n-1,j,INT_MIN,atlantic);
        }
        vector<vector<int>>vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    vec.push_back({i,j});
                }
            }
        }
        return vec;
    }
};