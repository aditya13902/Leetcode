// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        stack<int>st;
        vector<int>lft(n,-1);
        vector<int>rgt(n,-1);
        for(int i=0;i<n;i++){
            while(st.size() && st.top()<arr[i]){
                st.pop();
            }
            if(st.size()){
                lft[i]=st.top();
            }
            else{
                lft[i]=arr[i];
                st.push(arr[i]);
            }
            
            
        }
        while(st.size()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(st.size() && st.top()<arr[i]){
                st.pop();
            }
            if(st.size()){
                rgt[i]=st.top();
            }
            else{
                rgt[i]=arr[i];
                st.push(arr[i]);
            }
            
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            // cout<<min(lft[i],rgt[i])<<endl;
            ans+=((long long)min(lft[i],rgt[i])-(long long)arr[i]);
        }
        return ans;
        
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends