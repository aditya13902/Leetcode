class Solution {
public:
    static bool cmp(vector<int>&v1 ,vector<int>&v2){
        if(v1[0]==v2[0]){
            return v1[1]>v2[1];
        }
        return v1[0]<v2[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt=0;
        for(int i=1;i<intervals.size();i++){
            int s=intervals[i][0];
            int e=intervals[i][1];
            for(int j=i-1;j>=0;j--){
                int currs=intervals[j][0];
                int curre=intervals[j][1];
                if(s>=currs && e<=curre){
                    cnt++;
                    break;
                }
            }
        }
        return intervals.size()-cnt;
    }
};