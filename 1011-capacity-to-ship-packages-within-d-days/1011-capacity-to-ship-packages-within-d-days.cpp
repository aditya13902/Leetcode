class Solution {
    bool check(vector<int>& weights, int days,int val){
        int sum=0;
        int cnt=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            if(sum>val){
                sum=weights[i];
                cnt++;
            }
        }
        if(sum>0){
            cnt++;
        }
        return cnt<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        int s=0;
        for(auto ele:weights){
            s=max(s,ele);
            sum+=ele;
        }
        
        int e=sum;
        int ans=-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(check(weights,days,m)){
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