class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mp;
        for(auto str:strs){
            vector<int>vec(26,0);
            for(auto ele:str){
                vec[ele-'a']++;
            }
            mp[vec].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto ele:mp){
            ans.push_back(ele.second);
        }
        return ans;
    }
};