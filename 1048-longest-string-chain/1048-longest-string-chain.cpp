bool comp(string &s1,string &s2)
 {
        return s1.size()<s2.size();
 }

class Solution {
public:
    
    bool solve(string &a,string &b){
        int n=a.size();
        int m=b.size();
        
        if(m+1 != n){
            return false;
        }
        
        int i=0;
        int j=0;
        
        while(i<n){
            if(j<m && a[i] == b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        return (i==n && j==m);
    }
    
    int longestStrChain(vector<string>& a) {
        
        sort(a.begin(),a.end(),comp);
        int n = a.size();
        vector<int> dp(n,1);
        int maxx=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(solve(a[i],a[j])){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            if(maxx<dp[i]){
                maxx=dp[i];
            }
        }
        return maxx;
    }
};