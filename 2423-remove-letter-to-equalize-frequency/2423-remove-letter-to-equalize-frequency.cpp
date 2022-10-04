class Solution {
public:
    bool check(vector<pair<int,int>>vec,int f){
        if(f){
            vec[0].first--;
        }
        else{
            vec[vec.size()-1].first--;
        }
        unordered_set<int>st;
        for(auto ele:vec){
            if(ele.first!=0){
                st.insert(ele.first);
            }
        }
        return st.size()==1;
    }
    bool equalFrequency(string word) {
        unordered_map<int,int>mp;
        for(auto ch:word){
            mp[ch]++;
        }
        vector<pair<int,int>>vec;
        for(auto it:mp){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end());
        return check(vec,0)||check(vec,1);
    }
};