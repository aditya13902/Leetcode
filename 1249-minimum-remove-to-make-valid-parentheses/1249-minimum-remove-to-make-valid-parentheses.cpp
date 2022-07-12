class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        unordered_set<int>mp;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.size() && s[st.top()]=='(') st.pop();
                else{
                    mp.insert(i);
                }
            }
        }
        while(st.size()){
            mp.insert(st.top());
            st.pop();
        }
        string ans="";
        for(int i=0;i<s.size();i++){
            if(mp.find(i)==mp.end()){
                ans+=s[i];
            }
        }
        return ans;
    }
};