class Solution {
public:
    int helper(string s,int k,char ch){
        int j=0;
        int ans=0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=ch){
                cnt++;
            }
            while(cnt>k){
                if(s[j]!=ch){
                    cnt--;
                }
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        int ans=0;
        for(int i=0;i<26;i++){
            char curr='A'+i;
            ans=max(ans,helper(s,k,curr));
        }
        return ans;
    }
};