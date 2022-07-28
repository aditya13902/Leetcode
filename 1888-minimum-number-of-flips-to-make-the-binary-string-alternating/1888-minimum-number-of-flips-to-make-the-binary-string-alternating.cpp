class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        s+=s;
        string s1="";
        string s2="";
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                s1+='0';
                s2+='1';
            }
            else{
                s1+='1';
                s2+='0';
            }
        }
        int cnt1=0;
        int cnt2=0;
        int ans=n;
        for(int i=0;i<s.size();i++){
            if(s1[i]!=s[i]) cnt1++;
            if(s2[i]!=s[i]) cnt2++;
            if(i>=n){
                if(s[i-n]!=s1[i-n]) cnt1--;
                if(s[i-n]!=s2[i-n]) cnt2--;
            }
            if(i>=n-1) ans=min(ans,min(cnt1,cnt2));
        }
        return ans;
    }
};
// 11001

// 1010101010...
// 0101010101...