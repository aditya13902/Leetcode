class Solution {
public:
    vector<vector<int>>dp;
    // int helper(vector<int>&nums1,vector<int>&nums2,int i,int j,int f){
    //     if(i>=nums1.size() || j>=nums2.size()){
    //         return 0;
    //     }
    //     if(dp[i][j][f]!=-1){
    //         return dp[i][j][f];
    //     }
    //     if(f){
    //         int ans=max(helper(nums1,nums2,i+1,j,f),helper(nums1,nums2,i,j+1,f));
    //         if(nums1[i]==nums2[j]){
    //             ans=max(ans,1+helper(nums1,nums2,i+1,j+1,!f));
    //         }
    //         return dp[i][j][f]=ans;
    //     }
    //     else{
    //         if(nums1[i]==nums2[j]){
    //             return dp[i][j][f]=1+helper(nums1,nums2,i+1,j+1,f);
    //         }
    //         else{
    //             return dp[i][j][f]=0;
    //         }
    //     }
    // }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // dp.resize(nums1.size(),vector<vector<int>>(nums2.size(),vector<int>(2,-1)));
        // return helper(nums1,nums2,0,0,1);
        dp.resize(nums1.size()+1,vector<int>(nums2.size()+1,0));
        int ans=0;
        for(int i=1;i<=nums1.size();i++){
            for(int j=1;j<=nums2.size();j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0;
                }
                ans=max(dp[i][j],ans);
            }
        }
        return ans;
    }
};