class Solution {
public:
    bool flag(vector<int>&vec,int h,int k){
        int cnt=0;
        for(auto ele:vec){
            cnt+=ele/k;
            if(ele%k!=0){
                cnt++;
            }
        }
        return cnt<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int e=1;
        for(auto ele:piles){
            e=max(ele,e);
        }
        int ans=e;
        while(s<=e){
            int m=s+(e-s)/2;
            if(flag(piles,h,m)){
                ans=m;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return s;
    }
};