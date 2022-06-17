class Solution {
public:
    int diff=INT_MAX;
    int ans=INT_MAX;
    void helper(vector<int>& toppingCosts, int idx,int target,int cost){
        if(diff>abs(cost-target)){
            ans=cost;
            diff=abs(cost-target);
        }
        else if(diff==abs(cost-target)){
            ans=min(cost,ans);
        }
        if(idx==toppingCosts.size()){
            return;
        }
        for(int i=0;i<=2;i++){
            helper(toppingCosts,idx+1,target,cost+(toppingCosts[idx]*i));
        }
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        for(auto ele:baseCosts){
            helper(toppingCosts,0,target,ele);
        }
        return ans;
    }
};