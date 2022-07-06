class Solution {
public:
    // static bool cmp(vector<int>&v1,vector<int>&v2){
    //     return v1.size()>=v2.size();
    // }
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>>adj(n);
        for(auto vec:roads){
            adj[vec[0]].insert(vec[1]);
            adj[vec[1]].insert(vec[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                
                int siz1=adj[i].size();
                int siz2=adj[j].size();
                if(adj[i].find(j)==adj[i].end()){
                    ans=max(ans,siz1+siz2);
                }
                else{
                    ans=max(ans,siz1+siz2-1);
                }
            }
        }
        return ans;
    }
};