class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=INT_MIN;
        for(int i=0;i<nums.size();i++){
            res=max(res,nums[i]);
        }
        int currmin=1;
        int currmax=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                currmin=1;
                currmax=1;
            }
            else{
                int tmp=currmax*nums[i];
                currmax=max({currmax*nums[i],currmin*nums[i],nums[i]});
                currmin=min({tmp,currmin*nums[i],nums[i]});
                res=max(res,currmax);
            }
        }
        return res;
        
    }
};