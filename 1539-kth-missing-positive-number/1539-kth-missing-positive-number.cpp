class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l=0;
        int r=arr.size()-1;
        while(l<=r){
            int m=(l+r)/2;
            int miss=arr[m]-m;
            if(miss<=k){
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return l+k;
    }
};