class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int cnt=((n-i)*(i+1)+1)/2;
            sum+=(arr[i]*cnt);
            
        }
        
        return sum;
    }
};