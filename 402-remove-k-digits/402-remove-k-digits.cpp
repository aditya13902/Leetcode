class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.size();i++){
            while(k && st.size() && st.top()>num[i]){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        while(k && st.size()){
            st.pop();
            k--;
        }
        string ans="";
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        ans=ans.substr(i);
        return ans==""?"0":ans;
    }
};