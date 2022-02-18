class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()){
            return "0";
        }
        stack<char>stk;
        int i=0;
        while(i<num.length()){
            while(k>0 && stk.size() && num[i]<stk.top()){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
            i++;
        }
        while(k>0){
            stk.pop();
            k--;
        }
        string str="";
        while(stk.size()){
            str.push_back(stk.top());
            stk.pop();
        }
        reverse(str.begin(),str.end());
        while(str.length()>1 && str[0]=='0'){
            str.erase(0,1);
        }
        return str;
    }
};