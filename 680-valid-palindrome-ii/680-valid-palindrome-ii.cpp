class Solution {
public:
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                int i1=i+1;
                int j1=j;
                int i2=i;
                int j2=j-1;
                int f1=1;
                int f2=1;
                while(i1<j1){
                    if(s[i1]!=s[j1]){
                        f1=0;
                        break;
                    }
                    i1++;
                    j1--;
                }
                while(i2<j2){
                    if(s[i2]!=s[j2]){
                        f2=0;
                        break;
                    }
                    i2++;
                    j2--;
                }
                return f1||f2;
            }
            i++;
            j--;
        }
        return true;
        
        
    }
};