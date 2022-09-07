const int mod=1e9+7;
class Solution {
public:
    int arrLen;
    vector<vector<int>>dp;
    int memo(int steps,int i){
        if(i==0 && steps==0) return 1;
        if(steps==0 || i<0 || i>=arrLen || i>steps){
            return 0;
        }
        if(dp[steps][i]!=-1) return dp[steps][i];
        return dp[steps][i]=(memo(steps-1,i+1)+(memo(steps-1,i-1)+memo(steps-1,i))%mod)%mod;
    }
    int numWays(int steps, int arrLen) {
        this->arrLen=arrLen;
        dp.resize(1000,vector<int>(1000,-1));
        return memo(steps,0);
    }
};