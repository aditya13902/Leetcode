class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int curr=1;
        int cnt=0;
        while(cnt<k){
            int flag=0;
            for(int i=0;i<arr.size();i++){
                if(arr[i]==curr){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                cnt++;
            }
            curr++;
        }
        return curr-1;
    }
};