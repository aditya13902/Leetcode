class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n,-1);
        vector<int>right(n,-1);
        int mx=height[0];
        for(int i=0;i<n;i++){
            mx=max(mx,height[i]);
            left[i]=mx;
        }
        mx=height[n-1];
        for(int i=n-1;i>=0;i--){
            mx=max(mx,height[i]);
            right[i]=mx;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(left[i],right[i])-height[i]);
        }
        return ans;
        
    }
};