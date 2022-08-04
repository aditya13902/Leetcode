class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int mn=0;
        int mx=0;
        // int i=0;
        int cnt=1;
        while(mx<n){
            for(int i=0;i<ranges.size();i++){
                int l=max(0,i-ranges[i]);
                int r=min(n,i+ranges[i]);
                if(l<=mn && r>mx){
                    mx=r;
                }
            }
            if(mx>=n) break;
            if(mn==mx) return -1;
            mn=mx;
            cnt++;
        }
        return cnt;
    }
};