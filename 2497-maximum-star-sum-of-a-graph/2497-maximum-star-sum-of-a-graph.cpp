class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back({vals[edge[1]],edge[1]});
            adj[edge[1]].push_back({vals[edge[0]],edge[0]});
        }
        for(auto &vec:adj){
            sort(vec.rbegin(),vec.rend());
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int curr=vals[i];
            int cnt=0;
            for(auto p:adj[i]){
                ans=max(ans,curr);
                if(cnt==k){
                    break;
                }
                curr+=p.first;
                cnt++;
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};