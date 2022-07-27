class Solution {
public:
    bool check(vector<vector<char>>&board,int r,int c,char val){
        for(int i=0;i<9;i++){
            if(board[r][i]==val) return false;
            if(board[i][c]==val) return false;
        }
        int boxr=r-(r%3);
        int boxc=c-(c%3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[boxr+i][boxc+j]==val) return false;
            }
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board,int r,int c) {
        if(r==9){
            return true;
        }
        if(c==9) return solveSudoku(board,r+1,0);
        if(board[r][c]!='.')  return solveSudoku(board,r,c+1);
        
        for(char ch='1';ch<='9';ch++){
            if(check(board,r,c,ch)){
                board[r][c]=ch;
                if(solveSudoku(board,r,c+1)) return true;
                board[r][c]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board){
        solveSudoku(board,0,0);
    }
};