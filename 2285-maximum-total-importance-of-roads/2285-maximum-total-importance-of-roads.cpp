class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>degree(n,0);
        for(auto vec:roads){
            degree[vec[0]]++;
            degree[vec[1]]++;
        }
        sort(degree.begin(),degree.end(),greater<int>());
        long long sum=0;
        long long val=n;
        for(int i=0;i<n;i++){
            sum+=(degree[i]*val);
            val--;
        }
        return sum;
    }
};