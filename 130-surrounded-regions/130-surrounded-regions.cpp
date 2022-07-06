class Solution {
public:
    void dfs(vector<vector<char>>& board,int i,int j){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return;
        }
        if(board[i][j]!='O'){
            return;
        }
        board[i][j]='#';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' &&(i==0 || j==0 || i==n-1 || j==m-1)){
                    dfs(board,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=(board[i][j]=='#')?'O':'X';
            }
        }
    }
};