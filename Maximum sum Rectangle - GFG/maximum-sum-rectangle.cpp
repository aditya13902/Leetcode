// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kadane(vector<int>&vec){
        int n=vec.size();
        int ans=INT_MIN;
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=vec[i];
            ans=max(ans,curr);
            if(curr<0){
                curr=0;
            }
        }
        return ans;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int ans=INT_MIN;
        for(int i=0;i<R;i++){
            vector<int>sub(C,0);
            for(int j=i;j<R;j++){
                for(int c=0;c<C;c++){
                    sub[c]+=M[j][c];
                }
                ans=max(ans,kadane(sub));
            }
        }
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends