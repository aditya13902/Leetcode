class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open;
        stack<int>star;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                open.push(i);
            }
            else if(s[i]=='*'){
                star.push(i);
            }
            else{
                if(open.size()) open.pop();
                else if(star.size()) star.pop();
                else{
                    return false;
                }
            }
        }
        while(open.size()){
            if(star.size()==0) return false;
            if(open.top()<star.top()){
                open.pop();
                star.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }
};