class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dis(n,1e8);
        dis[src]=0;
        for(int i=0;i<=k;i++){
            vector<int>tmp=dis;
            for(auto vec:flights){
                if(tmp[vec[1]]>dis[vec[0]]+vec[2]){
                    tmp[vec[1]]=dis[vec[0]]+vec[2];
                }
            }
            dis=tmp;
        }
        return dis[dst]>=1e8?-1:dis[dst];
    }
};