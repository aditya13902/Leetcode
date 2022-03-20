class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>from;
        unordered_map<int,int>to;
        for(auto ele:trust){
            from[ele[0]]++;
            to[ele[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(to[i]==n-1 && from[i]==0){
                return i;
            }
        }
        return -1;
    }
};