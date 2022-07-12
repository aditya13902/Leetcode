class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>mp;
        for(auto vec:adjacentPairs){
            mp[vec[0]].push_back(vec[1]);
            mp[vec[1]].push_back(vec[0]);
        }
        vector<int>res;
        for(auto it:mp){
            if(it.second.size()==1){
                res.push_back(it.first);
                res.push_back(it.second[0]);
                break;
            }
        }
        while(res.size()<adjacentPairs.size()+1){
            int curr=res[res.size()-1];
            int prev=res[res.size()-2];
            auto vec=mp[curr];
            for(auto ele:vec){
                if(ele!=prev){
                    res.push_back(ele);
                }
            }
        }
        return res;
    }
};