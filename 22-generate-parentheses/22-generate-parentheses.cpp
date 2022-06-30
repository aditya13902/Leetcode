class Solution {
public:
    vector<string>ans;
    void helper(int n,string str,int s,int e){
        if(s==n && e==n){
            ans.push_back(str);
            return;
        }
        if(s>n){
            return;
        }
        if(s>=e){
            if(s==e){
                helper(n,str+'(',s+1,e);
            }
            else{
                helper(n,str+'(',s+1,e);
                helper(n,str+')',s,e+1);
            }
        }
        else{
            return;
        }
    }
    vector<string> generateParenthesis(int n) {
        helper(n,"",0,0);
        return ans;
    }
};