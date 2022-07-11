class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size()){
            return false;
        }
        unordered_map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second & 1){
                cnt++;
            }
        }
        return cnt<=k;
        
    }
};