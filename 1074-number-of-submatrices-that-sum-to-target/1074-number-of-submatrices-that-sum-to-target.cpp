class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            int sum=0;
            for(int j=0;j<matrix[0].size();j++){
                sum+=matrix[i][j];
                matrix[i][j]=sum;
            }
        }
        int ans=0;
        for(int c1=0;c1<matrix[0].size();c1++){
            for(int c2=c1;c2<matrix[0].size();c2++){
                unordered_map<int,int>mp;
                int sum=0;
                mp[0]=1;
                for(int r=0;r<matrix.size();r++){
                    sum+=matrix[r][c2]-((c1==0)?0:matrix[r][c1-1]);
                    // ans+=mp[sum-target]+mp[target-sum];
                    // sum+=matrix[r][c2]-(c1>0?matrix[r][c1-1]:0);
                    if(mp[sum-target]) ans+=mp[sum-target];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};