class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_set<int>st;
        int s=0;
        int ans=0;
        for(int e=0;e<str.size();e++){
            while(st.find(str[e])!=st.end()){
                st.erase(str[s]);
                s++;
            }
            ans=max(ans,e-s+1);
            st.insert(str[e]);
        }
        return ans;
    }
};