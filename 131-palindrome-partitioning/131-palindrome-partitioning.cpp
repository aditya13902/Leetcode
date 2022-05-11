class Solution {
public:
    // int mx=0;
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
    vector<vector<string>>ans;
    void helper(string s,vector<string>&vec,int idx){
        if(idx>=s.size()){
            // mx=max(vec.size(),mx);
            ans.push_back(vec);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(pali(s,idx,i)){
                vec.push_back(s.substr(idx,i-idx+1));
                helper(s,vec,i+1);
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>vec;
        helper(s,vec,0);
        return ans;
    }
};