class Solution {
public:
    int merge(vector<int>&arr,int l,int m,int r){
        int i=l;
        int j=m+1;
        int ans=0;
        while(i<=m && j<=r){
            if((long long)arr[i]>(long long) 2*arr[j]){
                ans+=(m-i+1);
                j++;
            }
            else{
                i++;
            }
        }
        sort(arr.begin()+l,arr.begin()+r+1);
        return ans;
    }
    int mergesort(vector<int>&arr,int i,int j){
        int ans=0;
        if(i<j){
            int m=i+(j-i)/2;
            ans+=mergesort(arr,i,m);
            ans+=mergesort(arr,m+1,j);
            ans+=merge(arr,i,m,j);
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};