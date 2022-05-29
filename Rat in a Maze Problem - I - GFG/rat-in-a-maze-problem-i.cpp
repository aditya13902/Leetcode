// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    void helper(vector<vector<int>> &m,int i,int j,string &s){
        if(i<0 ||j<0 || i>=m.size() ||j>=m.size() || m[i][j]==0 || m[i][j]==-1){
            return;
        }
        if(i==m.size()-1 && j==m.size()-1){
            ans.push_back(s);
        }
        m[i][j]=-1;
        s.push_back('R');
        helper(m,i,j+1,s);
        s.pop_back();
        s.push_back('L');
        helper(m,i,j-1,s);
        s.pop_back();
        s.push_back('U');
        helper(m,i-1,j,s);
        s.pop_back();
        s.push_back('D');
        helper(m,i+1,j,s);
        s.pop_back();
        m[i][j]=1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string s="";
        helper(m,0,0,s);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends