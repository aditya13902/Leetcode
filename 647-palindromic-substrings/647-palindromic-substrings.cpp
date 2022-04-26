class Solution {
    vector<vector<int>>vec;
public:
    int helper(string s,int i,int j){
        if(i>=j){
            return 1;
        }
        if(vec[i][j]!=-1){
            return vec[i][j];
        }
        if(s[i]==s[j]){
            return vec[i][j]=helper(s,i+1,j-1);
        }
        else{
            return vec[i][j]=0;
        }
    }
    int countSubstrings(string s) {
        int cnt=0;
        vec.resize(s.size(),vector<int>(s.size(),-1));
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                cnt+=helper(s,i,j);
            }
        }
        return cnt;
    }
};