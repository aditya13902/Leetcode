class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dis(n,1e9);
        dis[src]=0;
        for(int t=0;t<=k;t++){
            vector<int>tmp=dis;
            for(auto vec:flights){
                if(dis[vec[1]]>tmp[vec[0]]+vec[2]){
                    dis[vec[1]]=tmp[vec[0]]+vec[2];
                }
            }
        }
        return dis[dst]==1e9?-1:dis[dst];
    }
};