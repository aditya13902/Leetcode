class Solution {
public:
    vector<vector<int>>dp;
    bool helper(string s1,string s2,string s3,int i,int j,int k){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==s1.size() && j==s2.size() && k==s3.size()){
            return true;
        }
        if(i==s1.size()){
            while(j<s2.size() && k<s3.size() && s2[j]==s3[k]){
                j++;
                k++;
            }
            return j==s2.size() && k==s3.size();
        }
        if(j==s2.size()){
            while(i<s1.size() && k<s3.size() && s1[i]==s3[k]){
                i++;
                k++;
            }
            return i==s1.size() && k==s3.size();
        }
        bool tmp=false;
        if(s1[i]==s3[k]){
            tmp|=helper(s1,s2,s3,i+1,j,k+1);
        }
        if(s2[j]==s3[k]){
            tmp|=helper(s1,s2,s3,i,j+1,k+1);
        }
        return dp[i][j]=tmp;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return helper(s1,s2,s3,0,0,0);
    }
};