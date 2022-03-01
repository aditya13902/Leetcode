class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long long>st;
        for(int i=0;i<nums.size();i++){
            if(i>k){
                st.erase(st.find(nums[i-k-1]));
            }
            
            auto pos1=st.lower_bound((long long)nums[i]-t);
            auto pos2=st.upper_bound((long long)nums[i]+t);
            if(pos1!=pos2){
                return true;
            }
            st.insert((long long)nums[i]);
        }
        return false;
    }
};