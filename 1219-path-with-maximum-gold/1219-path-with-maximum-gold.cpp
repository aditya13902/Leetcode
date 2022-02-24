class Solution {
public:
	int dx[4]={-1,1,0,0};
	int dy[4]={0,0,-1,1};
	int dfs(vector<vector<int>> &grid,int i,int j,int r,int c,vector<vector<bool>> &visited){
		if(i<0 || i>=r || j<0 || j>=c || grid[i][j]==0 || visited[i][j]) return 0; //base case 
		int res=0;
		visited[i][j]=true;
		for(int k=0;k<4;k++)  //traversing in all four direction
			res=max(res,dfs(grid,i+dx[k],j+dy[k],r,c,visited));

		visited[i][j]=false; //need to set false because it should be made available for other path
		return grid[i][j]+res;
	}
	int getMaximumGold(vector<vector<int>>& grid) {
		 int ans=0,r=grid.size(),c=grid[0].size();
		vector<vector<bool>> visited(r,vector<bool>(c,false));
		 for(int i=0;i<r;i++){
			 for(int j=0;j<c;j++){
				 if(grid[i][j]!=0){   //for every cell which is not zero
					 ans=max(ans,dfs(grid,i,j,r,c,visited));
				 }
			 }
		 }
		return ans;
	}
};