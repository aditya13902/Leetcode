class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX;
        int ans=0;
        for(int i=0;i<prices.size();i++){
            if(mn<prices[i]){
                ans+=prices[i]-mn;
                mn=prices[i];
            }
            else{
                mn=prices[i];
            }
        }
        return ans;
    }
};