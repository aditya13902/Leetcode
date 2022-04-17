class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            int m=i+(j-i)/2;
            if(arr[m]<arr[m+1]){
                i=m+1;
            }
            else{
                j=m;
            }
        }
        return i;
    }
};