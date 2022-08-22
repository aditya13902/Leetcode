class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dis(n,1e8);
        dis[src]=0;
        for(int m=0;m<=k;m++){
            vector<int> tmp=dis;
            for(auto vec:flights){
                if(dis[vec[1]]>tmp[vec[0]]+vec[2]){
                    dis[vec[1]]=tmp[vec[0]]+vec[2];
                }
            }
        }
        return dis[dst]==1e8?-1:dis[dst];
    }
};