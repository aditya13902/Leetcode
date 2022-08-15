class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mps;
        unordered_map<char,int>mpt;
        for(auto ch:t) mpt[ch]++;
        
        int i=0;
        int strt=-1;
        int len=INT_MAX;
        int have=0;
        int need=mpt.size();
        for(int j=0;j<s.size();j++){
            mps[s[j]]++;
            if(mpt[s[j]] && mps[s[j]]==mpt[s[j]]){
                have++;
            }
            while(have==need){
                if(j-i+1<len){
                    strt=i;
                    len=j-i+1;
                }
                
                mps[s[i]]--;
                if(mpt[s[i]] && mps[s[i]]<mpt[s[i]]){
                    have--;
                }
                i++;
            }
        }
        if(len==INT_MAX) return "";
        return s.substr(strt,len);
    }
};