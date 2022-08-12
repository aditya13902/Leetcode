class Solution {
public:
    bool checkValidString(string s) {
        int open=0;
        int close=0;
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }
            else if(s[i]==')'){
                close++;
            }
            else{
                cnt++;
            }
            
            if(open+cnt-close<0) return false;
            
        }
        open=0;
        close=0;
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')') close++;
            else if(s[i]=='(') open++;
            else cnt++;
            
            if(close+cnt-open<0) return false;
        }
        return true;
    }
};