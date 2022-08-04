class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int siz=n+m;
        int i=0;
        int j=n;
        while(true){
            int cnt1=(i+j)/2;
            int cnt2=((siz+1)/2)-cnt1;
            
            int l1=cnt1==0?INT_MIN:nums1[cnt1-1];
            int l2=cnt2==0?INT_MIN:nums2[cnt2-1];
            int r1=cnt1==n?INT_MAX:nums1[cnt1];
            int r2=cnt2==m?INT_MAX:nums2[cnt2];
            if(l1<=r2 && l2<=r1){
                if(siz&1){
                    return max(l1,l2);
                }
                else{
                    return (double)(max(l1,l2)+min(r1,r2))/2.0;
                }
            }
            else if(l1>r2){
                j=cnt1-1;
            }
            else{
                i=cnt1+1;
            }
            
        }
        return -1;
    }
};