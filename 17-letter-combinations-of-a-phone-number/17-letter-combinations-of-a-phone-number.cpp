class Solution {
public:
    vector<string> phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    void helper(string& digits,int idx,string& str){
        if(idx==digits.size()){
            ans.push_back(str);
            return;
        }
        int n=digits[idx]-'0';
        for(int i=0;i<phone[n].size();i++){
            str.push_back(phone[n][i]);
            helper(digits,idx+1,str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return ans;
        }
        string str="";
        helper(digits,0,str);
        return ans;
    }
};