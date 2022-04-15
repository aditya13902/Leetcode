// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        
        // your code here
        sort(a,a+size);
        int mid=size/2;
        int cnt=1;
        for(int i=mid-1;i>=0 && a[mid]==a[i];i--){
            cnt++;
        }
        for(int i=mid+1;i<size && a[mid]==a[i];i++){
            cnt++;
        }
        if(cnt<=size/2){
            return -1;
        }
        return a[mid];
        
        
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends