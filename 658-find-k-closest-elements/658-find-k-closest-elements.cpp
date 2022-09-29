class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        vector<int>ans;
        int i=idx;
        int j=idx-1;
        while(i<arr.size() && j>=0 && k){
            if(arr[i]-x<x-arr[j]){
                ans.push_back(arr[i++]);
            }
            else{
                ans.push_back(arr[j--]);
            }
            k--;
        }
        while(j>=0 && k){
            ans.push_back(arr[j--]);
            k--;
        }
        while(i<arr.size() && k){
            ans.push_back(arr[i++]);
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};