class cmp{
public:
    bool operator()(vector<int>&v1,vector<int>&v2){
        if(v1[0]==v2[0]){
            return v1[1]<v2[1];
        }
        return v1[0]>v2[0];
    }
};
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& vec) {
        sort(vec.begin(),vec.end(),cmp());
        int mx=INT_MIN;
        int cnt=0;
        for(int i=0;i<vec.size();i++){
            // cout<<vec[i][0]<<" "<<vec[i][1]<<endl;
            
            if(vec[i][1]<mx){
                cnt++;
            }
            // cout<<cnt<<endl;
            mx=max(mx,vec[i][1]);
        }
        return cnt;
    }
};