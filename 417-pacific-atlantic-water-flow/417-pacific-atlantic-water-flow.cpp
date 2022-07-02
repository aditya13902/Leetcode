class Solution {
public:
    void flow(vector<vector<int>>& heights,int i,int j,int prev,vector<vector<int>>& ocean){
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size()){
            return;
        }
        if(heights[i][j]<prev) return;
        if(ocean[i][j]==1) return;
        ocean[i][j]=1;
        flow(heights,i+1,j,heights[i][j],ocean);
        flow(heights,i,j-1,heights[i][j],ocean);
        flow(heights,i-1,j,heights[i][j],ocean);
        flow(heights,i,j+1,heights[i][j],ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            flow(heights,i,0,INT_MIN,pacific);
            flow(heights,i,m-1,INT_MIN,atlantic);
        }
        for(int j=0;j<m;j++){
            flow(heights,0,j,INT_MIN,pacific);
            flow(heights,n-1,j,INT_MIN,atlantic);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }
};