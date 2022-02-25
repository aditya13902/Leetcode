class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        if(v1[1]==v2[1]){
            return v1[0]<v2[0];
        }
        return v1[1]<v2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int end=points[0][1];
        int cnt=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]>end){
                cnt++;
                end=points[i][1];
            }
        }
        return cnt;
    }
};
// 1,16 2,8 4,6 5,6
// 