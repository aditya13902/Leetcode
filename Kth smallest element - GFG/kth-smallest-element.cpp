//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int helper(int nums[], int l, int r, int k) {
        //code here
        int idx=l;
        int tmp=nums[r];
        for(int i=l;i<r;i++){
            if(nums[i]<=tmp){
                swap(nums[idx],nums[i]);
                idx++;
            }
        }
        swap(nums[idx],nums[r]);
        if(idx==k){
            return nums[idx];
        }
        else if(idx<k){
            return helper(nums,idx+1,r,k);
        }
        else{
            return helper(nums,l,idx-1,k);
        }
    }
    int kthSmallest(int arr[], int l, int r, int k){
        k--;
        return helper(arr,l,r,k);
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends