//{ Driver Code Starts
// C++ Program to count pairs whose sum divisible
// by '4'
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int count4Divisibiles(int arr[], int n)
    {
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]%4!=0 && mp.find(4-(arr[i]%4))!=mp.end()){
                ans+=mp[4-(arr[i]%4)];
            }
            else if(arr[i]%4==0){
                ans+=mp[0];
            }
            mp[arr[i]%4]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
         cin>>arr[i];
        Solution ob;
        cout << ob.count4Divisibiles(arr, n)<<endl;
    }
 
    return 0;
}
// } Driver Code Ends