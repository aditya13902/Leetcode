class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int mn=0;
        int mx=0;
        int cnt=0;
        while(mx<time){
            for(int i=0;i<clips.size();i++){
                if(clips[i][0]<=mn && clips[i][1]>mx){
                    mx=clips[i][1];
                }
            }
            if(mn==mx){
                return -1;
            }
            cnt++;
            mn=mx;
        }
        return cnt;
    }
};