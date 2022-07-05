class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto ele:wordDict){
            st.insert(ele);
        }
        vector<int>dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    string curr=s.substr(j,i-j);
                    if(st.find(curr)!=st.end()){
                        dp[i]=true;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};