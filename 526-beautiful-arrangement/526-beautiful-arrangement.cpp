class Solution {
public:
    int ans=0;
    void dfs(int n,int pos,vector<bool>&flag){
        if(pos>n){
            ans++;
            return;
        }
        for(int i=1;i<=n;i++){
            if(!flag[i] && (i%pos==0 || pos%i ==0)){
                flag[i]=true;
                dfs(n,pos+1,flag);
                flag[i]=false;  //backtrack
            }
        }
    }
    int countArrangement(int n) {
        vector<bool>flag(16,false);
        if(n<4){
            return n;
        }
        dfs(n,1,flag);
        return ans;
        
    }
};