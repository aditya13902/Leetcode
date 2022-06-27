class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0){
            return "";
        }
        sort(strs.begin(),strs.end());
        auto strt=strs[0];
        auto end=strs[n-1];
        string ans="";
        for(int i=0;i<strt.size();i++){
            if(strt[i]==end[i]){
                ans+=strt[i];
            }
            else{
                break;
            }
        }
        return ans;
    }
};