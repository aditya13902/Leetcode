class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        for(int idx=0;idx<t.size();idx++){
            if(i<s.size() && s[i]==t[idx]){
                i++;
            }
        }
        return i==s.size();
    }
};