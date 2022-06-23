class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,1e9);
        dist[src]=0;
        for(int i=0;i<=k;i++){
            vector<int>temp=dist;
            for(auto edge:flights){
                if(edge[2]+dist[edge[0]]<temp[edge[1]]){
                    temp[edge[1]]=edge[2]+dist[edge[0]];
                }
            }
            dist=temp;
        }
        return dist[dst]==1e9 ?-1:dist[dst];
    }
};
// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
//         vector<int> dist(n, INT_MAX);
//         dist[src]=0;
//         for(int i=0; i<=k; i++) {
//             vector<int> temp(n);
//             copy(dist.begin(), dist.end(), temp.begin());
//             for(auto e : edges) {
//                 if(dist[e[0]]==INT_MAX)
//                     continue;
//                 if(temp[e[1]]>dist[e[0]]+e[2])
//                     temp[e[1]]=dist[e[0]]+e[2];
//             }
//             copy(temp.begin(), temp.end(), dist.begin());
//         }
//         if(dist[dst]==INT_MAX)
//             return -1;
//         return dist[dst];
//     }
// };