class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_map<char,unordered_set<char>>mp;
        for(auto v:mappings){
            mp[v[0]].insert(v[1]);
        }
        for(int i=0;i<s.length();++i){
            bool flag = true;
            for(int j=0;j<sub.length();++j){
                if(s[i+j]==sub[j]){
                    continue;
                }
                else if(!mp[sub[j]].count(s[i+j])){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};