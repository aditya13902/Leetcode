class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        long long mid=num/3;
        long long fst=mid-1;
        long long sec=mid+1;
        vector<long long>ans;
        if(mid+fst+sec==num){
            ans.push_back(fst);
            ans.push_back(mid);
            ans.push_back(sec);
        }
        return ans;
    }
};