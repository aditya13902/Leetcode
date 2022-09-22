class Solution {
public:
    string reverseWords(string s) {
        string str="";
        string curr="";
        for(auto ch:s){
            if(ch==' '){
                reverse(curr.begin(),curr.end());
                str+=curr;
                str+=' ';
                curr="";
            }
            else{
                curr+=ch;
            }
        }
        reverse(curr.begin(),curr.end());
        str+=curr;
        return str;
    }
};