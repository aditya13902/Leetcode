class Solution {
public:
    bool checkValidString(string s) {
        int currmx=0;
        int currmn=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                currmn++;
                currmx++;
            }
            else if(s[i]==')'){
                currmn--;
                currmx--;
            }
            else{
                currmx++;
                currmn--;
            }
            if(currmx<0) return false;
            currmn=max(0,currmn);
        }
        return currmn==0;
    }
};