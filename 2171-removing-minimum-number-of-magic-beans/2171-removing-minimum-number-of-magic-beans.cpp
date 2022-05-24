class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        int n=beans.size();
        sort(beans.begin(),beans.end());
        long long sum=0;
        for(auto ele:beans){
            sum+=ele;
        }
        long long sub=0;
        long long ans=sum;
        for(int i=0;i<n;i++){
            long long sub=(long long)beans[i]*(long long)(n-i);
            ans=min(ans,sum-sub);

        }
        return ans;
    }
};