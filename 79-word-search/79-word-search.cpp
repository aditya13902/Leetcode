class Solution {
    bool dfs(vector<vector<char>>&board,string word,int i,int j, map<pair<int,int>,int>&mp,int idx=0){
        if(idx==word.size()){
            return true;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || mp[{i,j}]==1){
            return false;
        }
        if(board[i][j]==word[idx]){
            mp[{i,j}]=1;
            bool dir1=dfs(board,word,i+1,j,mp,idx+1);
            bool dir2=dfs(board,word,i,j+1,mp,idx+1);
            bool dir3=dfs(board,word,i-1,j,mp,idx+1);
            bool dir4=dfs(board,word,i,j-1,mp,idx+1);
            mp[{i,j}]=0;
            return dir1||dir2||dir3||dir4;
        }
        else{
            return false;
        }
        
    }
public:
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    map<pair<int,int>,int>mp;
                    if(dfs(board,word,i,j,mp)){
                        cout<<i<<","<<j<<endl;
                        return true;
                    }
                }
            }
        }
        return false;
    }
};