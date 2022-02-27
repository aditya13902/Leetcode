class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        for(auto ch:t){
            mp[ch]--;
        }
        int cnt=0;
        for(auto it:mp){
            cnt+=abs(it.second);
        }
        return cnt;
    }
};
//"cotxazilut"
//"nahrrmcchxwrieqqdwdpneitkxgnt"