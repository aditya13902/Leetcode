class Solution {
private:
    void count(string& s,int &cnt0,int &cnt1){
        for(auto ch:s){
            if(ch=='0') cnt0++;
            else cnt1++;
        }
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(auto str:strs){
            int cnt0=0;
            int cnt1=0;
            count(str,cnt0,cnt1);
            for(int i=m;i>=cnt0;i--){
                for(int j=n;j>=cnt1;j--){
                    dp[i][j]=max(dp[i][j],1+dp[i-cnt0][j-cnt1]);
                }
            }
        }
        return dp[m][n];
    }
};