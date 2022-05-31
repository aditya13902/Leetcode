class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto str:wordDict){
            st.insert(str);
        }
        vector<int>dp(s.size()+1,0);
        dp[0]=1;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                string sub=s.substr(j,i-j);
                if(st.find(sub)!=st.end()){
                    // cout<<sub<<endl;
                    if(dp[j]){
                        // cout<<i<<endl;
                        dp[i]=1;
                    }
                    
                }
            }
        }
        return dp[s.size()];
    }
};