class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(auto ch:s){
            if(st.size() && st.top().first==ch){
                auto p=st.top();
                st.pop();
                p.second++;
                if(p.second!=k){
                    st.push(p);
                }
            }
            else{
                st.push({ch,1});
            }
        }
        string ans="";
        while(st.size()){
            auto [ch,t]=st.top();
            while(t--){
                ans+=ch;
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};