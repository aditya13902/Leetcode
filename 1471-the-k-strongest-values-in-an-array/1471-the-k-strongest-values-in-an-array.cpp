class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int>ans;
        int i=0;
        int j=arr.size()-1;
        sort(arr.begin(),arr.end());
        int m=arr[(arr.size()-1)/2];
        while(i<=j && k>0){
            if(abs(arr[i]-m) <= abs(arr[j]-m)){
                ans.push_back(arr[j]);
                j--;
            }
            else{
                ans.push_back(arr[i]);
                i++;
            }
            k--;
        }
        return ans;
    }
};