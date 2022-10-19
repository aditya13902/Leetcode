class Solution {
public:
    struct cmp{
        bool operator()(const pair<string,int>&a, const pair<string,int>&b) const {
            if(a.second==b.second){
                return a.first<b.first;
            }
            return a.second>b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(auto str:words){
            mp[str]++;
        }
        
        vector<pair<string,int>>vec;
        for(auto& it:mp){
            vec.push_back(it);
        }
        sort(vec.begin(),vec.end(),cmp());
        vector<string>out;
        for(int i=0;i<k;i++){
            out.push_back(vec[i].first);
        }
        return out;
            
    }
};