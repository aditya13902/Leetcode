class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        for(auto str:words){
            mp[str]++;
        }
        int len=0;
        int cnt=0;
        for(auto str:words){
            auto rev=str;
            reverse(rev.begin(),rev.end());
            if(mp[str]){
                if(rev!=str){
                    len+=min(mp[str],mp[rev])*4;
                    mp[str]=0;
                    mp[rev]=0;
                }
            }
        }
        int add=0;
        for(auto str:words){
            if(mp[str]){
                add+=(mp[str]/2)*4;
                if(mp[str]%2 && cnt==0){
                    add+=2;
                    cnt++;
                }
                mp[str]=0;
            }
        }
        return len+add;
    }
};