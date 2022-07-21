class Solution {
public:
    vector<vector<string>>ans;
    bool pali(string str){
        int i=0;
        int j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void helper(string s,int idx,string str,vector<string>&curr){
        if(idx==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=idx;i<s.size();i++){
            str+=s[i];
            if(pali(str)){
                curr.push_back(str);
                helper(s,i+1,"",curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        helper(s,0,"",curr);
        return ans;
    }
};