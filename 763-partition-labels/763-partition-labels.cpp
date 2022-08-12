class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int>mp; // index of last appearence
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        int i=0;
        int j=0;
        int prev=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            if(i>j){
                ans.push_back(j-prev+1);
                j=i;
                prev=i;
            }
            j=max(j,mp[s[i]]);
        }
        ans.push_back(j-prev+1);
        return ans;
        
    }
};