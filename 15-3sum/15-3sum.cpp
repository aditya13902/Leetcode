class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size() < 3){   
            return {};
        }
        if(nums[0] > 0){        
            return {};
        }
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i!=0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int first=nums[j];
                    int last=nums[k];
                    while(j<k && nums[j]==last){
                        j++;
                    }
                    while(j<k && nums[k]==last){
                        k--;
                    }
                    
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else if(nums[i]+nums[j]+nums[k]<0){
                    j++;
                }
            }
        }
        return ans;
    }
};