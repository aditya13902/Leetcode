// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  vector<vector<int>>dp;
    int helper(string A,int i,int j){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==j){
            return 1;
        }
        if(A[i]==A[j]){
            return dp[i][j]=2+helper(A,i+1,j-1);
        }
        else{
            return dp[i][j]=max(helper(A,i,j-1),helper(A,i+1,j));
        }
    }
    int longestPalinSubseq(string A) {
        //code here
        dp.resize(A.size(),vector<int>(A.size(),-1));
        return helper(A,0,A.size()-1);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends