class Solution {
public:
    int ans=0;
    int helper(vector<vector<int>>&mat,unordered_set<int>&st){
        int cnt=0;
        for(int r=0;r<mat.size();r++){
            int f=1;
            for(int c=0;c<mat[0].size();c++){
                if(mat[r][c]==1){
                    if(st.find(c)==st.end()){
                        f=0;
                    }
                }
            }
            if(f){
                cnt++;
            }
        }
        return cnt;
    }
    void rec(vector<vector<int>>&mat,int i,unordered_set<int>& st,int c){
        if(c==0){
            ans=max(ans,helper(mat,st));
            return;
        }
        if(i==mat[0].size()) return;
        rec(mat,i+1,st,c);
        st.insert(i);
        rec(mat,i+1,st,c-1);
        st.erase(i);
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        int n=mat.size();
        int m=mat[0].size();
        unordered_set<int>st;
        rec(mat,0,st,cols);
        
        return ans;
    }
};