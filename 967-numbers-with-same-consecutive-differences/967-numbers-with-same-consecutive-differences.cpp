class Solution {
public:
    vector<int>ans;
    void helper(int n,int k,int num,int p){
        if(n==0){
            ans.push_back(num);
            return;
        }
        if(p+k<10){
            int curr=num;
            num=num*10+(p+k);
            helper(n-1,k,num,p+k);
            num=curr;
        }
        if(p-k>=0 && k!=0){
            int curr=num;
            num=num*10+(p-k);
            helper(n-1,k,num,p-k);
            num=curr;
        }
        return;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){
            helper(n-1,k,i,i);
        }
        return ans;
    }
};