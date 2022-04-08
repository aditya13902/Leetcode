class Solution {
    int _n;
    vector<int>dp;
    int dfs(int num){
        if(num==1){
            return 1;
        }
        if(dp[num]!=-1){
            return dp[num];
        }
        int res=0;
        if(num!=_n){
            res=num;
        }
        for(int i=1;i<num;i++){
            int val=dfs(num-i)*dfs(i);
            res=max(res,val);
        }
        return dp[num]=res;
    }
public:
    int integerBreak(int n) {
        _n=n;
        dp.resize(n+1,-1);
        dp[1]=1;
        return dfs(n);
        
    }
};