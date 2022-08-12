class cmp{
public:
    bool operator()(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
    }
    
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp());
        int e=points[0][1];
        int cnt=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]>e){
                e=points[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};