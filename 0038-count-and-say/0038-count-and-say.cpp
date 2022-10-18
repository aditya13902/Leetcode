class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        auto str=countAndSay(n-1);
        int cnt=0;
        string ans="";
        for(int i=0;i<str.size();i++){
            if(i!=0 && str[i]==str[i-1]) continue;
            int cnt=0;
            // string curr="";
            for(int j=i;j<str.size();j++){
                if(str[i]==str[j]){
                    cnt++;
                }
                else{
                    break;
                }
                // curr+=str[j];
            }
            ans=ans+to_string(cnt)+str[i];
        }
        // cout<<ans<<endl;
        return ans;
    }
};