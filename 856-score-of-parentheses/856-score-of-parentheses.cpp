class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        for(auto ch:s){
            if(ch=='('){
                st.push(0);
            }
            else{
                int curr=0;
                while(st.top()!=0){
                    curr+=st.top();
                    st.pop();
                }
                st.pop();
                st.push(max(2*curr,1));
            }
        }
        int ans=0;
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};