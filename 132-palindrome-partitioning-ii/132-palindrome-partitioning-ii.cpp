class Solution {
public:
    vector<int>dp;
    bool pali(string &curr){
        int i=0;
        int j=curr.size()-1;
        while(i<j){
            if(curr[i]!=curr[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int helper(string &s,int idx){
        if(idx==s.size()) return -1;
        int ans=s.size();
        string curr="";
        if(dp[idx]!=-1) return dp[idx];
        for(int i=idx;i<s.size();i++){
            curr+=s[i];
            if(pali(curr)){
                ans=min(ans,1+helper(s,i+1));
            }
        }
        return dp[idx]=ans;
    }
    int minCut(string s) {
        dp.resize(s.size(),-1);
        return helper(s,0);
    }
};