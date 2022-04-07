class Solution {
    vector<vector<int>>ans;
    void helper(int n,int k,int s,vector<int>&vec){
        if(k==0){
            ans.push_back(vec);
            return;
        }
        if(s>n){
            return;
        }
        for(int i=s;i<=n;i++){
            vec.push_back(i);
            helper(n,k-1,i+1,vec);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int>vec;
        helper(n,k,1,vec);
        return ans;
    }
};