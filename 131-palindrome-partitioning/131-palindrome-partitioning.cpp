class Solution {
public:
    bool pali(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void helper(string s,vector<string>&vec,vector<vector<string>>&ans,int idx){
        if(idx>=s.size()){
            ans.push_back(vec);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(pali(s,idx,i)){
                vec.push_back(s.substr(idx,i-idx+1));
                helper(s,vec,ans,i+1);
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>vec;
        vector<vector<string>>ans;
        helper(s,vec,ans,0);
        return ans;
    }
};