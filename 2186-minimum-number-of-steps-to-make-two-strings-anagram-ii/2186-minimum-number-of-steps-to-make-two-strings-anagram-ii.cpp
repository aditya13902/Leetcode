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
            if(it.second<0){
                cnt-=it.second;
            }
            else{
                cnt+=it.second;
            }
            
        }
        return cnt;
    }
};
//"cotxazilut"
//"nahrrmcchxwrieqqdwdpneitkxgnt"