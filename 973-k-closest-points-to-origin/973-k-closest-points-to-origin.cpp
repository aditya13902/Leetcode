class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(auto vec:points){
            int x=vec[0];
            int y=vec[1];
            pq.push({x*x+y*y,{x,y}});
        }
        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            auto top=pq.top();
            pq.pop();
            ans.push_back({top.second.first,top.second.second});
        }
        return ans;
    }
};