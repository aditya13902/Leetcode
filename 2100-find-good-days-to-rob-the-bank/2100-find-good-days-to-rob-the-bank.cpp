class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& arr, int time) {
        int n=arr.size();
        vector<int>lft(n,0);
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1]){
                lft[i]=lft[i-1]+1;
            }
        }
        vector<int>rgt(n,0);
        for(int i=n-2;i>=0;i--){
            if(arr[i+1]>=arr[i]){
                rgt[i]=1+rgt[i+1];
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(lft[i]>=time && rgt[i]>=time) ans.push_back(i);
        }
        return ans;
    }
};