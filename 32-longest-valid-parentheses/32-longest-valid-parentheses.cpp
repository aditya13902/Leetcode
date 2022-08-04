class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0;
        int close=0;
        int ans=0;
        for(auto ch:s){
            if(ch=='('){
                open++;
            }
            else{
                close++;
            }
            if(close>open){
                open=0;
                close=0;
            }
            else if(open==close){
                ans=max(ans,open+close);
            }
        }
        open=0;
        close=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')') close++;
            else open++;
            
            if(open==close){
                ans=max(ans,open+close);
            }
            else if(open>close){
                open=0;
                close=0;
            }
        }
        return ans;
    }
};