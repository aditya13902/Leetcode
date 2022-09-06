class Solution {
public:
    bool check(vector<int>&piles,int h,int m){
        long long  cnt=0;
        for(auto ele:piles){
            cnt+=(ele/m);
            if(ele%m) cnt++;
            if(cnt>h) return false;
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=1e9;
        int ans=-1;
        while(s<=e){
            int m=(s)+(e-s)/2;
            if(check(piles,h,m)){
                ans=m;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return ans;
    }
};