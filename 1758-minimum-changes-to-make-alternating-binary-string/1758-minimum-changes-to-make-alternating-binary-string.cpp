class Solution {
public:
    int helper(string &s,int i,char prev){
        if(i>=s.size()) return 0;
        if(s[i]==prev){
            char opp=(s[i]=='0')?'1':'0';
            return 1+helper(s,i+1,opp);
        }
        else{
            return helper(s,i+1,s[i]);
        }
    }
    int minOperations(string s) {
        int ans=s.size();
        ans=min(ans,helper(s,1,s[0]));
        char opp=(s[0]=='0')?'1':'0';
        ans=min(ans,1+helper(s,1,opp));
        return ans;
    }
};
// 01111