class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st;
        for(auto ele:nums1) st.insert(ele);
        vector<int>ans;
        for(auto ele:nums2){
            if(st.find(ele)!=st.end()){
                ans.push_back(ele);
                st.erase(ele);
            }
        }
        return ans;
    }
};