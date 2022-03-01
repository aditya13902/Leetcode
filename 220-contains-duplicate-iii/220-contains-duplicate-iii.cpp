class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<int,int>>vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            for(int j=i+1;j<vec.size();j++){
                if((long long)vec[j].first<=(long long)t+vec[i].first){
                    if(abs(vec[i].second-vec[j].second)<=k){
                        return true;
                    }
                }
                else{
                    break;
                }
            }
        }
        return false;
    }
};