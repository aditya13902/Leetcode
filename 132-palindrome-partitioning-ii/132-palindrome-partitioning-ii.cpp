class Solution {
private:
    bool pali(string &curr,int i,int j){
        while(i<j){
            if(curr[i]!=curr[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0]=-1;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]!=INT_MAX && pali(s,j,i-1)){
                    dp[i]=min(dp[i],1+dp[j]);
                }
            }
        }
        return dp[n];
        
    }
};