class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>tmap;
        unordered_map<char,int>smap;
        int i=0;
        int j=0;
        int need=0;
        for(auto ch:t){
            if(tmap[ch]==0){
                need++;
            }
            tmap[ch]++;
        }
        int have=0;
        int strt=-1;
        int len=INT_MAX;
        while(j<s.size()){
            smap[s[j]]++;
            if(tmap[s[j]] && tmap[s[j]]==smap[s[j]]) have++;
            
            while(have==need){
                if(len>(j-i+1)){
                    len=j-i+1;
                    strt=i;
                }
                smap[s[i]]--;
                if(tmap[s[i]] && smap[s[i]]<tmap[s[i]]){
                    have--;
                }
                i++;
            }
            j++;
        }
        if(len==INT_MAX) return "";
        
        return s.substr(strt,len);
    }
};