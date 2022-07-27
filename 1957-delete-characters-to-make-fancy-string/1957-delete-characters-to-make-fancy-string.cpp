class Solution {
public:
    string makeFancyString(string s) {
        // int cnt=1;
        int curr=1;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(i>0 && s[i]==s[i-1]){
                curr++;
                if(curr<3){
                    ans+=s[i];
                }
            }
            else{
                ans+=s[i];
                curr=1;
            }
        }
        return ans;
    }
};