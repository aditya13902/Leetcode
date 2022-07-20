class Solution {
public:
    int dp[50][50];
    bool memo(string s,string p,int i,int j){
        if(i>=s.size() && j>=p.size()) return true;
        if(j>=p.size()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool flag=(i<s.size() && (s[i]==p[j] || p[j]=='.'));
        
        if(j+1<p.size() && p[j+1]=='*'){
            return dp[i][j]= memo(s,p,i,j+2) ||(flag && memo(s,p,i+1,j));
        }
        if (flag){
            return dp[i][j]=memo(s,p,i+1,j+1);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        for(int i=0;i<50;i++){
            for(int j=0;j<50;j++){
                dp[i][j]=-1;
            }
        }
        return memo(s,p,0,0);
    }
};