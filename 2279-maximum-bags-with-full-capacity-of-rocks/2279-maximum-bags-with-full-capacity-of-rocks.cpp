class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int additionalRocks) {
        multiset<int>st;
        int n=rocks.size();
        for(int i=0;i<n;i++){
            st.insert(cap[i]-rocks[i]);
        }
        int cnt=0;
        for(auto ele:st){
            // cout<<ele<<" ";
            additionalRocks-=ele;
            if(additionalRocks<0) break;
            cnt++;
        }
        return cnt;
        
    }
};