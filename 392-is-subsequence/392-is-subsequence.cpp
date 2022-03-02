class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;// string s matching
        for(int j=0;j<t.size();j++){
            if(i<s.size() && t[j]==s[i]){
                i++;
            }
        }
        return i==s.size();
    }
};
// ahcgdb
