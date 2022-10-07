class Solution {
public:
    int lcs(string text1, string text2) {
        vector<int>prev(text2.size()+1,0);
        for(int i=1;i<=text1.size();i++){
            vector<int>curr(text2.size()+1,0);
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    curr[j]=max(curr[j],1+prev[j-1]);
                }
                curr[j]=max({curr[j],prev[j],curr[j-1]});
            }
            prev=curr;
        }
        return prev[text2.size()];
        
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
};