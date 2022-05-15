class Solution {
public:
    bool ispal(string &s,int j,int i){
        while(j<i){
            if(s[j]==s[i]){
                j++;
                i--;
                
            }
            else{
                return false;
            }
        }
        return true;
    }
    int minCut(string s) {
        vector<int>dp(s.size());
        dp[0]=0;
        for(int i=1;i<s.size();i++){
            dp[i]=i;
            for(int j=i;j>=0;j--){
                if(ispal(s,j,i)){
                    if(j==0){
                        dp[i]=0;
                    }
                    else{
                        dp[i]=min(dp[i],1+dp[j-1]);
                    }
                }
            }
        }
        return dp[s.size()-1];
    }
};