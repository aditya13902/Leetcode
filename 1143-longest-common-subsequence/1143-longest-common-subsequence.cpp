class Solution {
public:
    vector<vector<int>>memo;
    int rec(string &s,string &t,int i,int j){
        if(i==s.size() || j==t.size()) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int ans=max(rec(s,t,i+1,j),rec(s,t,i,j+1));
        if(s[i]==t[j]){
            ans=max(ans,1+rec(s,t,i+1,j+1));
        }
        return memo[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        memo.resize(text1.size(),vector<int>(text2.size(),-1));
        return rec(text1,text2,0,0);
    }
};