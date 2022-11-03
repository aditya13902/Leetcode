class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;
        for(auto str:words){
            mp[str]++;
        }
        int ans=0;
        int f=0;
        for(auto it:mp){
            auto [str,cnt]=it;
            auto curr=str;
            reverse(curr.begin(),curr.end());
            if(curr!=str && mp[curr]){
                ans+=min(mp[curr],mp[str])*4;
                mp[curr]=0;
            }
            else if(curr==str){
                ans+=((mp[curr]/2)*4);
                if(mp[curr]%2 && !f){
                    ans+=2;
                    f=1;
                }
            }
        }
        return ans;
    }
};