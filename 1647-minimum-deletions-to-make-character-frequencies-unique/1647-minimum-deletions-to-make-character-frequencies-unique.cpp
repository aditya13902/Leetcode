class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        unordered_set<int>st;
        int cnt=0;
        for(auto [ch,freq]:mp){
            while(st.find(freq)!=st.end()){
                freq--;
                cnt++;
            }
            if(freq>0){
                st.insert(freq);
            }
        }
        return cnt;
    }
};