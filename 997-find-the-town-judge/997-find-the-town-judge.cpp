class Solution {
public:
    unordered_map<int,int>from;
    unordered_map<int,int>to;
    int findJudge(int n, vector<vector<int>>& trust) {
        for(auto vec:trust){
            from[vec[0]]++;
            to[vec[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(from[i]==0 && to[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};