class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(st.size() && st.top()<=arr[i]){
                st.pop();
            }
            if(st.size()){
                left[i]=st.top();
            }
            else{
                left[i]=arr[i];
                st.push(arr[i]);
            }
        }
        while(st.size()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(st.size() && st.top()<=arr[i]){
                st.pop();
            }
            if(st.size()){
                right[i]=st.top();
            }
            else{
                right[i]=arr[i];
                st.push(arr[i]);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(left[i],right[i])-arr[i]);
        }
        return ans;
    }
};