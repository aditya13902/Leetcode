class Solution {
public:
    bool check(string& s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,INT_MAX);
        dp[n-1]=0;
        // dp[n]=0;
        for(int i=n-2;i>=0;i--){
            for(int j=i;j<n;j++){
                if(check(s,i,j)){
                    if(j==n-1){
                        dp[i]=0;
                        break;
                    }
                    int subans=1+dp[j+1];
                    dp[i]=min(dp[i],subans);
                }
            }
        }
        return dp[0];
    }
};