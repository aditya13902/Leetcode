//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<int>par;
    int get(int v){
        if(par[v]==v) return v;
        return par[v]=get(par[v]);
    }
    void Union(int a,int b){
        a=get(a);
        b=get(b);
        par[b]=a;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n=accounts.size();
        par.resize(n);
        for(int i=0;i<n;i++) par[i]=i;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string str=accounts[i][j];
                if(mp.find(str)==mp.end()){
                    mp[str]=i;
                }
                else{
                    Union(mp[str],i);
                }
            }
        }
        map<int,vector<string>>ans;
        for(int i=0;i<n;i++){
            int v=get(i);
            // cout<<v<<endl;
            for(int j=1;j<accounts[i].size();j++){
                string str=accounts[i][j];
                ans[v].push_back(str);
            }
        }
        
        vector<vector<string>>vec;
        for(auto it:ans){
            set<string>sub;
            
            for(auto str:it.second){
                sub.insert(str);
            }
            vector<string>curr;
            curr.push_back(accounts[it.first][0]);
            for(auto ele:sub){
                curr.push_back(ele);
            }
            // for(auto str:sub) cout<<str<<" ";
            vec.push_back(curr);
        }
        return vec;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends