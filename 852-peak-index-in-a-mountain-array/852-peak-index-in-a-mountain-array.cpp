class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int r=arr.size()-1;
        int ans=0;
        while(l<=r){
            int m=l+(r-l)/2;
            if(m==0 || arr[m]>arr[m-1]){
                ans=m;
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return ans;
    }
};