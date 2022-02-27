class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        for(auto str:words){
            if(pref.size()>str.size()){
                continue;
            }
            int flag=true;
            for(int i=0;i<pref.size();i++){
                if(str[i]!=pref[i]){
                    flag=false;
                }
            }
            if(flag){
                cnt++;
            }
        }
        return cnt;
    }
};