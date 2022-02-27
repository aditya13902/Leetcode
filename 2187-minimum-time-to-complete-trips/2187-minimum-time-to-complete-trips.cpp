class Solution {
public:
    bool helper(vector<int>&time,int totalTrips,long long t){
        for(auto ele:time){
            if(totalTrips<=0){
                break;
            }
            totalTrips-=(t/ele);
        }
        return totalTrips<=0;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        // sort(time.begin(),time.end());
        long long mx=0;
        for(auto ele:time){
            if(mx<ele){
                mx=ele;
            }
        }
        long long s=1;
        long long e=mx*totalTrips+1;
        while(s<e){
            long long mid=s+(e-s)/2;
            if(helper(time,totalTrips,mid)){
                e=mid;
            }
            else{
                s=mid+1;
            }
        }
        return s;
    }
};