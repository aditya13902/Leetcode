class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto ele:nums){
            st.insert(ele);
        }
        int ans=0;
        for(auto ele:nums){
            if(st.find(ele+1)==st.end()){
                int curr=ele;
                int cnt=0;
                while(st.find(curr)!=st.end()){
                    cnt++;
                    curr--;
                }
                ans=max(cnt,ans);
            }
        }
        return ans;
    }
};