class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i=2;i<=numRows;i++){
            vector<int>subans(i,1);
            for(int j=1;j<i-1;j++){
                subans[j]=ans[i-2][j-1]+ans[i-2][j];
            }
            ans.push_back(subans);
        }
        return ans;
    }
};