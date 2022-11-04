class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset<int>st;
        for(auto ele:nums) st.insert(ele);
        while(st.size()){
            auto it=st.begin();
            int num=*it;
            st.erase(it);
            int cnt=1;
            while(cnt!=k && st.size()){
                if(st.find(num+1)==st.end()){
                    break;
                }
                st.erase(st.find(num+1));
                cnt++;
                num++;
            }
            if(cnt!=k) return false;
        }
        return true;
    }
};