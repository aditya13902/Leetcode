class Solution {
public:
    string reverseWords(string s) {
        string sub="";
        stack<string>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(sub!=""){
                    st.push(sub);
                }
                sub="";
            }
            else{
                sub.push_back(s[i]);
            }
        }
        if(sub!=""){
            st.push(sub);
        }
        string str="";
        while(st.size()){
            auto top=st.top();
            st.pop();
            str+=top;
            if(st.size()){
                str+=" ";
            } 
        }
        return str;
    }
};