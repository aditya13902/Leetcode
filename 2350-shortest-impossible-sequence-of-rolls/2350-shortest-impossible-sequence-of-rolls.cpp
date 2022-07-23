class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int>st;
        int len=0;
        for(auto ele:rolls){
            st.insert(ele);
            if(st.size()==k){
                len++;
                st.clear();
            }
        }
        return len+1;
    }
};