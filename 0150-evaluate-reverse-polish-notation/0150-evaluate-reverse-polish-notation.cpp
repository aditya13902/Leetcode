class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        for(auto str:tokens){
            if(str=="+"){
                long long a=st.top();
                st.pop();
                long long b=st.top();
                st.pop();
                st.push(a+b);
            }
            else if(str=="-"){
                long long a=st.top();
                st.pop();
                long long b=st.top();
                st.pop();
                st.push(b-a);
            }
            else if(str=="*"){
                long long a=st.top();
                st.pop();
                long long b=st.top();
                st.pop();
                st.push((long long)a*b);
            }
            else if(str=="/"){
                long long a=st.top();
                st.pop();
                long long b=st.top();
                st.pop();
                // cout<<<<endl;
                st.push(b/a);
            }
            else{
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};