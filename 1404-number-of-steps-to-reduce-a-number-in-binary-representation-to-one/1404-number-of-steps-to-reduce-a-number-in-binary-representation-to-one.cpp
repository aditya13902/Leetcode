class Solution {
public:
    int numSteps(string s) {
        int cnt=0;
        for(int i=s.size()-1;i>0;){
            if(s[i]=='1'){
                // cout<<cnt<<"--";
                cnt++;
                while(i>=0 && s[i]!='0'){
                    i--;
                    cnt++;
                }
                if(i>=0){
                    s[i]='1';
                }
                // cout<<cnt<<endl;
            }
            else{
                cnt++;
                i--;
            }
        }
        return cnt;
    }
};
// "110" --> 11 --> 100-->10-->1
// "111"--> 1000 -->100-->10-->1
// "1001" -->1010-->101-->110-->11-->100-->10-->1