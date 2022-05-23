class Solution {
public:
    const int N=1e8;
    vector<vector<int>>dp;
    // map<pair<int,int>,int>mp;
    int helper(vector<int>& vec,int l,int p){
        if(p==vec.size()){
            return 0;
        }
        if(vec[p]==l){
            return N;
        }
        
        if(dp[p][l]!=-1){
            return dp[p][l];
        }
        int ans=N;
        ans=min(ans,helper(vec,l,p+1));
        if(ans==N){
            for(int i=1;i<=3;i++){

                if(i!=l){
                    ans=min(ans,1+helper(vec,i,p));
                }
            }    
        }
        
        return dp[p][l]=ans;
    }
    int minSideJumps(vector<int>& obstacles) {
        dp.resize(obstacles.size()+1,vector<int>(4,-1));
        return helper(obstacles,2,0);
    }
};