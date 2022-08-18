class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);
        for(int i=0;i<heights.size();i++){
            while(st.size() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()){
                left[i]=st.top();
            }
            st.push(i);
        }
        while(st.size()){
            st.pop();
        }
        for(int i=heights.size()-1;i>=0;i--){
            while(st.size() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()){
                right[i]=st.top();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans=max(ans,(right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
};