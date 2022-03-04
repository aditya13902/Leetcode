class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double>prev;
        prev.push_back((double)poured);
        while(query_row--){
            vector<double>curr;
            curr.push_back(max((prev[0]-1)/2,0.0));
            for(int i=1;i<prev.size();i++){
                curr.push_back(max((prev[i-1]-1)/2,0.0)+max((prev[i]-1)/2,0.0));
            }
            curr.push_back(curr[0]);
            prev=curr;
        }
        return min(1.0,prev[query_glass]);
    }
};