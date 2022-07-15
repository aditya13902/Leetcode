class Solution {
public:
    bool check(vector<int>& bloomDay,int m,int k,int curr){
        int ptrcnt=0;
        int cnt=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=curr){
                ptrcnt++;
            }
            else{
                ptrcnt=0;
            }
            if(ptrcnt==k){
                cnt++;
                ptrcnt=0;
            }
        }
        return cnt>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=1;
        int e=1;
        for(auto ele:bloomDay) e=max(e,ele);
        
        int ans=-1;
        while(s<=e){
            int curr=(s+e)/2;
            if(check(bloomDay,m,k,curr)){
                ans=curr;
                e=curr-1;
            }
            else{
                s=curr+1;
            }
        }
        return ans;
    }
};