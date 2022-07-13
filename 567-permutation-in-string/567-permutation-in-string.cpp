class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>mp1(26,0);
        for(auto ch:s1) mp1[ch-'a']++;
        int i=0;
        vector<int>mp2(26,0);
        for(int j=0;j<s2.size();j++){
            mp2[s2[j]-'a']++;
            if(j-i>=s1.size()){
                mp2[s2[i]-'a']--;
                i++;
            }
            if(mp1==mp2) return true;
        }
        return false;
    }
};