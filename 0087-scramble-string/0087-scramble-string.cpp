class Solution {
public:
    unordered_map<string,int>mp;
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;
        
        if(mp.find(s1+'$'+s2)!=mp.end()) return mp[s1+'$'+s2];
        int len = s1.length();
        int count[26] = {0};
        for(int i=0; i<len; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return mp[s1+'$'+s2]=false;
        }
        
        
        for(int i=1; i<=len-1; i++)
        {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return mp[s1+'$'+s2]=true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return mp[s1+'$'+s2]=true;
        }
        return mp[s1+'$'+s2]=false;
    }
};