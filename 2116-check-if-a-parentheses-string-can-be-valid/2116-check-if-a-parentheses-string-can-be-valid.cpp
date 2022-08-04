class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()&1) return false;
        int open=0;
        int close=0;
        int unlock=0;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0'){
                unlock++;
            }
            else if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
            
            if(unlock<(close-open)) return false;
            
        }
        open=0;
        close=0;
        unlock=0;
        for(int i=s.size()-1;i>=0;i--){
            if(locked[i]=='0') unlock++;
            else if(s[i]==')') close++;
            else open++;
            
            if(unlock<(open-close)) return false;
            
        }
        return true;
    }
};