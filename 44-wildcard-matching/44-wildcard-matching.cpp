class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<int>prev(m+1,0);
        prev[0]=1;
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*') prev[i]=prev[i-1];
            else{
                prev[i]=0;
            }
        }
        for(int i=1;i<=n;i++){
            vector<int>curr(m+1,0);
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    curr[j]=prev[j-1];
                }
                else if(p[j-1]=='*'){
                    curr[j]=prev[j] || curr[j-1];
                }
                else{
                    curr[j]=0;
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};