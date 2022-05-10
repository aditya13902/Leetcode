// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(str1.size()+1,vector<int>(str2.size()+1,0));
	    for(int i=0;i<=str1.size();i++){
	        dp[i][0]=i;
	    }
	    for(int i=0;i<=str2.size();i++){
	        dp[0][i]=i;
	    }
	    for(int i=1;i<=str1.size();i++){
	        for(int j=1;j<=str2.size();j++){
	            if(str1[i-1]==str2[j-1]){
	                dp[i][j]=dp[i-1][j-1];
	            }
	            else{
	                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
	            }
	        }
	    }
	    return dp[str1.size()][str2.size()];
	    
	} 
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends