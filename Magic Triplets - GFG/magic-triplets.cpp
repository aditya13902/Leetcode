// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
	int countTriplets(vector<int>nums){
	   int count = 0;
       int length = nums.size();
       for(int i=1;i<length-1;i++) {
           int temp = 0;
           for(int j=i+1;j<length;j++)
           if(nums[j]>nums[i])
           temp++;
           int temp1 = 0;
           for(int j=i-1;j>=0;j--)
           if(nums[j]<nums[i])
           temp1++;
           count += temp*temp1;
       }
       return count;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends