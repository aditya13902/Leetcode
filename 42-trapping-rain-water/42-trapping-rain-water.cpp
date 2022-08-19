class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n);
        vector<int>right(n);
        
        stack<int>st;
        for(int i=0;i<n;i++){
            while(st.size() && st.top()<=height[i]){
                st.pop();
            }
            if(st.size()){
                left[i]=st.top();
            }
            else{
                left[i]=height[i];
                st.push(height[i]);
            }
        }
        while(st.size()) st.pop();
        
        for(int i=n-1;i>=0;i--){
            while(st.size() && st.top()<=height[i]){
                st.pop();
            }
            if(st.size()) {
                right[i]=st.top();
            }
            else{
                right[i]=height[i];
                st.push(height[i]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(left[i],right[i])-height[i]);
        }
        return ans;
    }
};