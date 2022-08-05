class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zero=0;
        int one=0;
        for(auto ch:s){
            if(ch=='0') zero++;
        }
        int ans=zero;
        for(auto ch:s){
            one+=(ch=='1');
            zero-=(ch=='0');
            ans=min(ans,one+zero);
        }
        return ans;
    }
};