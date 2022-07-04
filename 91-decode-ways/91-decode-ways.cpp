class Solution {
public:
    unordered_map<int,int>mp;
    int ways(string &s,int i){
        if(i==s.size()){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(mp.find(i)!=mp.end()){
            return mp[i];
        }
        int ans=ways(s,i+1);
        if(i+2<=s.size() && s.substr(i,2)<="26"){
            ans+=ways(s,i+2);
        }
        return mp[i]=ans;
    }
    int numDecodings(string s) {
        return ways(s,0);
    }
};