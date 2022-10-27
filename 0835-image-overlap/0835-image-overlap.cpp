class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>>vec1;
        vector<pair<int,int>>vec2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    vec1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    vec2.push_back({i,j});
                }
            }
        }
        int ans=0;
        map<pair<int,int>,int>mp;
        for(auto [i1,j1]:vec1){
            for(auto [i2,j2]:vec2){
                mp[{i1-i2,j1-j2}]++;
                ans=max(ans,mp[{i1-i2,j1-j2}]);
            }
        }
        return ans;
    }
};