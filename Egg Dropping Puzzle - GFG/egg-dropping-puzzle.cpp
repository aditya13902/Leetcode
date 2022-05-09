// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    vector<vector<int>>dp;
    int helper(int n,int k){
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        
        if(n<=1 || k==1){
            return n;
        }
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            ans=min(ans,max(helper(n-i,k),helper(i-1,k-1))+1);
        }
        return dp[n][k]=ans;
    }
    int eggDrop(int k, int n) 
    {
        dp.resize(n+1,vector<int>(k+1,-1));
        return helper(n,k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends