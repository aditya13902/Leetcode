class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mp1;
        unordered_map<char,bool>mp2;
        for(int i=0;i<s.size();i++){
            mp1[s[i]]=i;
            mp2[s[i]]=false;
        }
        
        
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(mp2[s[i]]){
                continue;
            }
            while(st.size()>0 && st.top()>s[i] && mp1[st.top()]>i){
                mp2[st.top()]=false;
                st.pop();
            }
            st.push(s[i]);
            mp2[s[i]]=true;
        }
        string ans = "";
        while (st.size() > 0){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};