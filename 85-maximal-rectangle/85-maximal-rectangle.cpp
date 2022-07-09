class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>lft(n,-1);
        vector<int>rgt(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(st.size() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()){
                lft[i]=st.top();
            }
            st.push(i);
            
        }
        while(st.size()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(st.size() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()){
                rgt[i]=st.top();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(rgt[i]-lft[i]-1)*heights[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        vector<int>vec(mat[0].size(),0);
        int ans=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]=='1'){
                    vec[j]+=1;
                }
                else{
                    vec[j]=0;
                }
            }
            ans=max(ans,largestRectangleArea(vec));
        }
        return ans;
    }
};