class Solution {
public:
    // set<int>st;
    vector<vector<int>>ans;
    void helper(int k,int n,vector<int>subans,int sum,int siz,int idx){
        if(siz>k || sum>n){
            return;
        }
        if(sum==n && siz==k){
            ans.push_back(subans);
            return;
        }
        for(int i=idx;i<=9;i++){
            if(i+sum<=n){
                // st.erase(i);
                subans.push_back(i);
                helper(k,n,subans,sum+i,siz+1,i+1);
                subans.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // for(int i=1;i<=9;i++){
        //     st.insert(i);
        // }
        vector<int>subans;
        helper(k,n,subans,0,0,1);
        return ans;
        
        
    }
};