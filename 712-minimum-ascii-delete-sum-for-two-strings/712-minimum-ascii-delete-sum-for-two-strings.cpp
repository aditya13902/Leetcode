class Solution {
public:
    vector<vector<int>>dp;
    int helper(string&s1,string&s2,int i,int j){
        if(i==s1.size() || j==s2.size()){
            int tot=0;
            for(int x=i;x<s1.size();x++) tot+=s1[x];
            for(int x=j;x<s2.size();x++) tot+=s2[x];
            return dp[i][j]=tot;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=helper(s1,s2,i+1,j+1);
        }
        int ans=min(s2[j]+helper(s1,s2,i,j+1),s1[i]+helper(s1,s2,i+1,j));
        return dp[i][j]=ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        dp.resize(s1.size()+1,vector<int>(s2.size()+1,-1));
        return helper(s1,s2,0,0);
    }
};