class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_set<char>st1;
        unordered_set<char>st2;
        vector<int>cnt1(26);
        vector<int>cnt2(26);
        for(auto ch:word1){
            st1.insert(ch);
            cnt1[ch-'a']++;
        }
        for(auto ch:word2){
            st2.insert(ch);
            cnt2[ch-'a']++;
        }
        sort(cnt1.begin(),cnt1.end());
        sort(cnt2.begin(),cnt2.end());
        return st1==st2 && cnt1==cnt2;
    }
};