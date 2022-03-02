class Solution {
public:
    unordered_set<string>st;
    void helper(string s,int idx,vector<string>& ans,string curr){
        if(idx>=s.size()){
            curr.pop_back();
            ans.push_back(curr);
        }
        string str="";
        for(int i=idx;i<s.size();i++){
            str+=s[i];
            if(st.find(str)!=st.end()){
                helper(s,i+1,ans,curr+str+" ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto ele:wordDict){
            st.insert(ele);
        }
        vector<string>ans;
        helper(s,0,ans,"");
        return ans;
    }
};