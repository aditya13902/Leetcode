class Solution {
public:
    int minAddToMakeValid(string s) {
        int curr=0;
        int mx1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') curr--;
            else curr++;
            mx1=max(mx1,curr);
        }
        int mx2=0;
        curr=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')') curr--;
            else curr++;
            mx2=max(mx2,curr);
        }
        return mx1+mx2;
        
    }
};
// (()()())()))