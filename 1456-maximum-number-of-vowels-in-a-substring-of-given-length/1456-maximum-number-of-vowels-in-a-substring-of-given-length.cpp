class Solution {
public:
    int mp[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1};
    int maxVowels(string s, int k) {
        int i=0;
        int cnt=0;
        int ans=0;
        for(int j=0;j<s.size();j++){
            if(j-i+1>k){
                cnt-=mp[s[i++]-'a'];
            }
            cnt+=mp[s[j]-'a'];
            ans=max(ans,cnt);
        }
        return ans;
    }
};