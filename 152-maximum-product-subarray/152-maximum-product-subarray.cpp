class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN;
        int currmax=1;
        int currmin=1;
        for(auto ele:nums){
            res=max(res,ele);
        }
        for(auto ele:nums){
            if(ele==0){
                currmin=1;
                currmax=1;
            }
            else{
                int tmp=currmax*ele;
                currmax=max({currmax*ele,currmin*ele,ele});
                currmin=min({tmp,currmin*ele,ele});
                res=max(res,currmax);
            }
        }
        return res;
    }
};