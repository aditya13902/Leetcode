class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>>vec;
        for(int i=0;i<startTime.size();i++){
            vec.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int>dp(vec.size(),0);
        for(int i=0;i<vec.size();i++){
            int include=vec[i][2];
            int s=0;
            int e=i-1;
            int idx=-1;
            while(s<=e){
                int m=(s+e)/2;
                if(vec[m][1]<=vec[i][0]){
                    idx=m;
                    s=m+1;
                }
                else{
                    e=m-1;
                }
            }
            if(idx!=-1){
                include+=dp[idx];
            }
            if(i>0){
               dp[i]=dp[i-1]; 
            }
            dp[i]=max(dp[i],include);
        }
        return dp[vec.size()-1];
    }
};