class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zero=0;
        int one=0;
        vector<int>lft(s.size(),0);
        vector<int>rgt(s.size(),0);
        for(int i=0;i<s.size();i++){
            lft[i]=one;
            if(s[i]=='1'){
                one++;
            }
            
        }
        for(int i=s.size()-1;i>=0;i--){
            rgt[i]=zero;
            if(s[i]=='0'){
                zero++;
            }
            
        }
        int ans=INT_MAX;
        for(int i=0;i<s.size();i++){
            ans=min(ans,lft[i]+rgt[i]);
        }
        return ans;
    }
};