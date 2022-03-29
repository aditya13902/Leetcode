class Solution {
    int helper(string s,string t,int l){
        int ans=0;
        for(int j=0;j<=t.size()-l;j++){
            string _t=t.substr(j,l);
            int c=0;
            for(int i=0;i<l;i++){
                if(s[i]!=_t[i]){
                    c++;
                }
            }
            if(c==1){
                ans++;
            }
        }
        return ans;
    }
public:
    int countSubstrings(string s,string t) {
        int cnt=0;
        for(int i=0;i<s.size();i++){
            for(int l=1;l<=s.size()-i;l++){
                string _s=s.substr(i,l);
                cnt+=helper(_s,t,l);
            }
        }
        return cnt;
        
    }
};