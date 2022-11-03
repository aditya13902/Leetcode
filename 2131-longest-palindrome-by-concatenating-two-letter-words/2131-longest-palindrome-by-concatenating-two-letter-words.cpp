class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>>cnt(26,vector<int>(26,0));
        int ans=0;
        for(auto str:words){
            int i=str[0]-'a';
            int j=str[1]-'a';
            if(cnt[j][i]){
                ans+=4;
                cnt[j][i]--;
            }
            else{
                cnt[i][j]++;
            }
        }
        for(int i=0;i<26;i++){
            if(cnt[i][i]==1){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};