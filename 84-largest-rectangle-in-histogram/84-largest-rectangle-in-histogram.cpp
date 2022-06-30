class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<pair<int,int>>st;
        int mxarea=0;
        for(int i=0;i<n;i++){
            int strt=i;
            while(st.size() && st.top().second>heights[i]){
                int idx=st.top().first;
                int h=st.top().second;
                mxarea=max(mxarea,(i-idx)*h);
                st.pop();
                strt=idx;
            }
            st.push({strt,heights[i]});
        }
        while(st.size()){
            int idx=st.top().first;
            int h=st.top().second;
            mxarea=max(mxarea,(n-idx)*h);
            st.pop();
        }
        return mxarea;
    }
};