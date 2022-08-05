class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int>st;
        int cnt=0;
        for(auto ele:rolls){
            st.insert(ele);
            if(st.size()==k){
                cnt++;
                st.clear();
            }
        }
        return cnt+1;
    }
};