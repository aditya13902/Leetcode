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
        for(int i=1;i<=n;i++){
            unordered_map<string,int>mp;
            for(auto str:strs){
                string curr=str.substr(0,i);
                mp[curr]++;
            }
            if(mp.size()==1){
                auto it=*mp.begin();
                ans=it.first;
            }
            else{
                break;
            }
        }
        return ans;
    }
};