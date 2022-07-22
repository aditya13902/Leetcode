class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lft(n,0);
        vector<int>rgt(n,0);
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,height[i]);
            lft[i]=mx;
            
        }
        mx=0;
        for(int i=n-1;i>=0;i--){
            mx=max(mx,height[i]);
            rgt[i]=mx;
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int curr=min(lft[i],rgt[i]);
            ans+=(curr-height[i]);
        }
        return ans;
    }
};