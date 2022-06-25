class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>R(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(st.size() && heights[st.top()]>heights[i]){
                R[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        vector<int>L(n,-1);
        stack<int>stl;
        for(int i=n-1;i>=0;i--){
            while(stl.size() && heights[stl.top()]>heights[i]){
                L[stl.top()]=i;
                stl.pop();
            }
            stl.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(R[i]-L[i]-1)*heights[i]);
        }
        return ans;
    }
};