class Solution {
public:
    bool check(string& str,int s,int e){
        while(s<e){
            if(str[s]!=str[e]){
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n);
        dp[0]=0;
        for(int i=1;i<n;i++){
            dp[i]=i;
            for(int j=0;j<=i;j++){
                if(check(s,j,i)){
                    if(j==0){
                        dp[i]=0;
                        break;
                    }
                    dp[i]=min(dp[i],1+dp[j-1]);
                }
            }
        }
        return dp[n-1];
    }
};