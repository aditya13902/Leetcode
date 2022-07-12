class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int i=0;
        int mx=0;
        for(int j=0;j<s.size();j++){
            while(st.find(s[j])!=st.end()){
                st.erase(s[i++]);
            }
            st.insert(s[j]);
            mx=max(mx,j-i+1);
        }
        return mx;
    }
};