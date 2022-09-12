class Solution {
public:
    vector<vector<int>>vis;
    int r;
    int c;
    bool find(vector<vector<char>>& board,int i,int j,string &word,int idx){
        if(idx==word.size()) return true;
        if(i<0 || j<0 || i>=r || j>=c || vis[i][j] || word[idx]!=board[i][j]) return false;
        vis[i][j]=1;
        bool op1=find(board,i+1,j,word,idx+1);
        bool op2=find(board,i-1,j,word,idx+1);
        bool op3=find(board,i,j+1,word,idx+1);
        bool op4=find(board,i,j-1,word,idx+1);
        vis[i][j]=0;
        return op1||op2||op3||op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        r=board.size();
        c=board[0].size();
        vis.resize(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0]){
                    if(find(board,i,j,word,0)) return true;
                }
            }
        }
        return false;
    }
};