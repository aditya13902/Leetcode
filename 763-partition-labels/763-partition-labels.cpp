class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        int i=0;
        int j=-1;
        vector<int>ans;
        while(i<s.size()){
            j=mp[s[i]];
            int cnt=0;
            while(i<s.size() && i<=j){
                j=max(j,mp[s[i]]);
                cnt++;
                i++;
            }
            ans.push_back(cnt);
        }
        return ans;
        
    }
};