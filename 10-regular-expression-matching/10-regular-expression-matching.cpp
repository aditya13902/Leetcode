class Solution {
public:
    int dp[21][31];
    bool memo(string &s,string &t,int i,int j){
        if(i>=s.size() && j>=t.size()) return true;
        if(j>=t.size()) return false;
        
        if(dp[i][j]!=-1){
             return dp[i][j];
        }
        bool flag=(i<s.size() && ( s[i]==t[j] || t[j]=='.' ));
        if(j+1<t.size() && t[j+1]=='*'){
            return dp[i][j]= memo(s,t,i,j+2) || (flag && i<s.size() && memo(s,t,i+1,j));
        }
        else if(flag){
            return dp[i][j]=memo(s,t,i+1,j+1);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        for(int i=0;i<=20;i++){
            for(int j=0;j<=30;j++){
                dp[i][j]=-1;
            }
        }
        return memo(s,p,0,0);
    }
};