class Solution {
public:
    int trap(vector<int>& height) {
        int siz=height.size();
        if(siz==0){
            return 0;
        }
        vector<int>left(siz);
        vector<int>right(siz);
        left[0]=height[0];
        right[siz-1]=height[siz-1];
        for(int i=1;i<siz;i++){
            left[i]=max(left[i-1],height[i]);
        }
        for(int i=siz-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<siz;i++){
            ans+=(min(left[i],right[i])-height[i]);
        }
        return ans;
    }
};