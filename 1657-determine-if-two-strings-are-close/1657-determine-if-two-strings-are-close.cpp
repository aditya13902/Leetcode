class Solution {
public:
    bool closeStrings(string word1, string word2) {
        multiset<int>st;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(auto ch:word1){
            mp1[ch]++;
        }
        for(auto it:mp1){
            st.insert(it.second);
        }
        
        for(auto ch:word2){
            mp2[ch]++;
        }
        for(auto it:mp2){
            if(mp1[it.first]!=0){
                if(st.find(it.second)!=st.end()){
                    st.erase(st.find(it.second));
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
        
    }
};