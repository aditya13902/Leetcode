class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp1;
        for(auto ch:s){
            mp1[ch]++;
        }
        unordered_map<char,int>mp2;
        for(auto ch:t){
            if(mp1[ch]){
                mp1[ch]--;
            }
            else{
                mp2[ch]++;
            }
        }
        int cnt=0;
        for(auto it:mp1){
            cnt+=it.second;
        }
        for(auto it:mp2){
            cnt+=it.second;
        }
        return cnt;
    }
};
//"cotxazilut"
//"nahrrmcchxwrieqqdwdpneitkxgnt"