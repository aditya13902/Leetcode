class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        if(v1[0]==v2[0]) return v1[1]>v2[1];
        return v1[0]<v2[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>ans;
        for(int i=0;i<envelopes.size();i++){
            auto it=lower_bound(ans.begin(),ans.end(),envelopes[i][1]);
            if(it==ans.end()){
                ans.push_back(envelopes[i][1]);
            }
            else{
                *it=envelopes[i][1];
            }
        }
        return ans.size();
    }
};