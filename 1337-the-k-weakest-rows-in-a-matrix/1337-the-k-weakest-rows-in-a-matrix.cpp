class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<mat.size();i++){
            int sum=0;
            for(int j=0;j<mat[0].size();j++){
                sum+=mat[i][j];
            }
            pq.push({-sum,-i});
        }
        vector<int>vec;
        while(k--){
            vec.push_back(-pq.top().second);
            pq.pop();
        }
        return vec;
    }
};