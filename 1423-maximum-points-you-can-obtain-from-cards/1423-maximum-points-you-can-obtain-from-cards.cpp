class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        for(int i=0;i<n;i++){
            pre[i]+=cardPoints[i];
            if(i>0){
                pre[i]+=pre[i-1];
            }
        }
        for(int j=n-1;j>=0;j--){
            suf[j]+=cardPoints[j];
            if(j+1<n) suf[j]+=suf[j+1];
        }
        reverse(suf.begin(),suf.end());
        int ans=max(pre[k-1],suf[k-1]);
        for(int i=1;i<k;i++){
            ans=max(ans,pre[i-1]+suf[k-i-1]);
        }
        return ans;
    }
};