class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        int bulls=0,cows=0;
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                mp1[secret[i]-'0']++;
                mp2[guess[i]-'0']++;
            }
        }
        for(auto it:mp1){
            if(mp2[it.first]){
                cows+=min(it.second,mp2[it.first]);
            }
        }
        string ans=to_string(bulls)+'A'+to_string(cows)+'B';
        return ans;
        
        
    }
};