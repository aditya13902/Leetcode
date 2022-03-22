class Solution {
public:
    string getSmallestString(int n, int k) {
        string str="";
        while(n>0){
            if(26*n<k){
                str.pop_back();
                k++;
                int rem=k-26*n;
                str+=('a'+rem-1);
                while(n--){
                    str+='z';
                }
                k=0;
            }
            else{
                if(n==1){
                    str+=('a'+k-1);
                    k=0;
                }
                else{
                   str+='a'; 
                    k--; 
                }
                
            }
            n--;
        }
        return str;
    }
};
// a b c d e f g hijklmnopqrst