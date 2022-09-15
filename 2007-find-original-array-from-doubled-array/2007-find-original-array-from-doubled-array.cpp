class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.rbegin(),changed.rend());
        multiset<int>st;
        vector<int>ans;
        for(auto ele:changed){
            if(st.find(2*ele)!=st.end()){
                ans.push_back(ele);
                st.erase(st.find(2*ele));
            }
            else{
                st.insert(ele);
            }
        }
        if(st.size()) return {};
        return ans;
    }
};