#define pb push_back
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==1){
            return {0,1};
        }
        vector<int> subans=grayCode(n-1);
        vector<int> ans;
        for(int i=0;i<subans.size();i++){
            ans.push_back(subans[i]);
        }
        for(int i=subans.size()-1;i>=0;i--){
            ans.push_back(subans[i]+(1<<(n-1)));
        }
        return ans;
    }
};