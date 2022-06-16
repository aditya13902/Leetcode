class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=text1.size();
        int j=text2.size();
        string str="";
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                str=text1[i-1]+str;
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    str=text1[i-1]+str;
                    i--;
                }
                else{
                    str=text2[j-1]+str;
                    j--;
                }
            }
        }
        while(j>0){
            str=text2[j-1]+str;
            j--;
        }
        while(i>0){
            str=text1[i-1]+str;
            i--;
        }
        return str;
        
    }
};
    // 0  c a b
    // a
    // b
    // a      z
    // c    y x