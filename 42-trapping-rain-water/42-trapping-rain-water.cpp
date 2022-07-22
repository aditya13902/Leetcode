class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int mxleft=height[0];
        int mxright=height[n-1];
        
        int l=1;
        int r=n-2;
        int ans=0;
        while(l<=r){
            if(mxleft<mxright){
                if(mxleft<height[l]){
                    mxleft=height[l];
                }
                else{
                    ans+=mxleft-height[l];
                }
                l++;
            }
            else{
                if(mxright<height[r]){
                    mxright=height[r];
                }
                else{
                    ans+=mxright-height[r];
                }
                r--;
            }
        }
        return ans;
    }
};