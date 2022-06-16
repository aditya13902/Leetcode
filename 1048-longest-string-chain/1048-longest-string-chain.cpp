bool cmp(string &s1,string &s2){
        return s1.size()<s2.size();
}
class Solution {
public:
    bool helper(string &curr,string &pre){
        int m=curr.size();
        int n=pre.size();
        if(m!=(n+1)){
            return false;
        }
        int i=0;
        int j=0;
        while(i<curr.size() && j<pre.size()){
            if(curr[i]==pre[j]){
                j++;
            }
            i++;
        }
        return j==pre.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        vector<int>dp(words.size(),1);
        int ans=1;
        for(int i=1;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(helper(words[i],words[j])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(dp[i],ans);
        }
        return ans;
    }
};