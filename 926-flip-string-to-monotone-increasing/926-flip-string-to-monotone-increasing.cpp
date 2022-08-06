class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt0=0;
        int cnt1=0;
        for(auto ch:s){
            if(ch=='0') cnt0++;
        }
        int ans=cnt0;
        for(int i=0;i<s.size();i++){
            cnt0-=(s[i]=='0');
            cnt1+=(s[i]=='1');
            ans=min(ans,cnt1+cnt0);
        }
        return ans;
    }
};