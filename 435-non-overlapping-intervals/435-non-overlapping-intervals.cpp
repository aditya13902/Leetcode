class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int prev=0;
        int cnt=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[prev][1]>intervals[i][0]){
                cnt++;
            }
            else{
                prev=i;
            }
        }
        return cnt;
    }
};