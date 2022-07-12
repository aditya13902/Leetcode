class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string str="";
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                if(str=="." || str==""){}
                else if(str==".."){
                    if(st.size()) st.pop();
                }
                else{
                    st.push(str);
                }
                str="";
            }
            else{
                str+=path[i];
            }
        }
        if(str=="." || str==""){}
        else if(str==".."){
            if(st.size()) st.pop();
        }
        else{
            st.push(str);
        }
        string res="";
        while(st.size()){
            res='/'+st.top()+res;
            st.pop();
        }
        return res==""?"/":res;
        
    }
};