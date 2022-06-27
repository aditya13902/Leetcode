class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=1000;
        for(auto str:strs){
            int siz=str.size();
            n=min(n,siz);
        }
        // string ans="";
        int idx=0;
        for(int i=1;i<=n;i++){
            unordered_map<char,int>mp;
            for(auto str:strs){
                char curr=str[i-1];
                mp[curr]++;
            }
            if(mp.size()==1){
                auto it=*mp.begin();
                idx=i;
            }
            else{
                break;
            }
        }
        ans=strs[0].substr(0,idx);
        return ans;
    }
};