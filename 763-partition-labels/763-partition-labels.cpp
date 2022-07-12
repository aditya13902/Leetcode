class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        int i=0;
        int cnt;
        vector<int>vec;
        while(i<s.size()){
            int j=mp[s[i]];
            cnt=0;
            while(i<=j){
                j=max(j,mp[s[i]]);
                cnt++;
                i++;
            }
            vec.push_back(cnt);
        }
        return vec;
        
    }
};