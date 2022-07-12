class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        if(v1[1]==v2[1]) return v1[0]<v2[0];
        return v1[1]<v2[1];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),cmp);
        set<int>st;
        int mx=events[events.size()-1][1];
        for(int i=1;i<=mx;i++) st.insert(i);
        int cnt=0;
        for(int i=0;i<events.size();i++){
            int s=events[i][0];
            int e=events[i][1];
            auto it=st.lower_bound(s);
            if(it==st.end() || *it>e) continue;
            else{
                st.erase(it);
                cnt++;
            }
        }
        return cnt;
    }
};