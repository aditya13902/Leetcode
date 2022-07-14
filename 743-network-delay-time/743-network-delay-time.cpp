class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        for(int i=0;i<n-1;i++){
            for(auto vec:times){
                if(dist[vec[0]]!=INT_MAX && dist[vec[0]]+vec[2]<dist[vec[1]]){
                    dist[vec[1]]=dist[vec[0]]+vec[2];
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;
            }
            ans=max(dist[i],ans);
        }
        return ans;
    }
};