class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nge(nums2.size(),-1);
        stack<int>st;
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
            while(st.size() && nums2[st.top()]< nums2[i]){
                nge[st.top()]=nums2[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=nge[mp[nums1[i]]];
        }
        return ans;
    }
};