class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int curr=1;
        int i=0;
        while(k){
            if(i<arr.size() && arr[i]==curr){
                curr++;
                i++;
            }
            else{
                curr++;
                k--;
            }
        }
        return curr-1;
    }
};