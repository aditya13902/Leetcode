class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int>dp(time+1,1e9);
        dp[0]=0;
        sort(clips.begin(),clips.end());
        for(int i=0;i<clips.size();i++){
            for(int j=clips[i][0];j<=clips[i][1] && j<=time;j++){
                dp[j]=min(dp[j],1+dp[clips[i][0]]);
            }
        }
        return dp[time]==1e9?-1:dp[time];
    }
};