class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(j>0){
                    matrix[i][j]+=matrix[i][j-1];
                }
            }
        }
        int cnt=0;
        for(int c1=0;c1<c;c1++){
            for(int c2=c1;c2<c;c2++){
                unordered_map<int,int>mp;
                mp[0]=1;
                int sum=0;
                for(int i=0;i<r;i++){
                    sum+=matrix[i][c2]-(c1>0?matrix[i][c1-1]:0);
                    if(mp[sum-target]>0){
                        cnt+=mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return cnt;
    }
};