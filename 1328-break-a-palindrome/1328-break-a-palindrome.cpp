class Solution {
public:
    string breakPalindrome(string str) {
        int n=str.size();
        char ch='a';
        int f=1;
        if(n==1) return "";
        for(int i=0;i<(n/2);i++){
            if(str[i]!=ch){
                str[i]=ch;
                f=0;
                break;
            }
        }
        if(f){
            str[n-1]='b';
        }
        return str;
    }
};