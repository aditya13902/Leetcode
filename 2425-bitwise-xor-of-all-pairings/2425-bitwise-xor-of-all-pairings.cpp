class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        for(auto ele:nums1){
            if(m%2){
                ans^=ele;
            }
        }
        for(auto ele:nums2){
            if(n%2){
                ans^=ele;
            }
        }
        return ans;
    }
};