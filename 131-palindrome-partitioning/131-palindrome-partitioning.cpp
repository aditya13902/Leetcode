class Solution {
public:
    vector<vector<string>> ans;
    bool flag(string& str,int i,int j){
        while(i<=j && str[i]==str[j]){
            i++;
            j--;
        }
        return i>j;
    }
    void helper(string& s,int idx,vector<string>&vec){
        if(idx==s.size()){
            ans.push_back(vec);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(flag(s,idx,i)){
                vec.push_back(s.substr(idx,i-idx+1));
                helper(s,i+1,vec);
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>vec;
        helper(s,0,vec);
        return ans;
    }
};