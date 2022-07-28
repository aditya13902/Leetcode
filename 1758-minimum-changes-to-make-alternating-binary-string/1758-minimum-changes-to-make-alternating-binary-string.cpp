class Solution {
public:
    int helper(string &s,int i,char prev){
        if(i>=s.size()) return 0;
        if(s[i]==prev){
            if(prev=='0'){
                return 1+helper(s,i+1,'1');
            }
            else{
                return 1+helper(s,i+1,'0');
            }
        }
        else{
            return helper(s,i+1,s[i]);
        }
    }
    int minOperations(string s) {
        int ans=s.size();
        ans=min(ans,helper(s,1,s[0]));
        char op=(s[0]=='0')?'1':'0';
        ans=min(ans,1+helper(s,1,op));
        return ans;
    }
};
// 01111