class Solution {
public:
    bool isHappy(int n) {
        // int sum=0;
        unordered_map<int,int>mp;
        while(n!=1){
            if(mp[n]!=0){
                return false;
            }
            mp[n]=1;
            int sum=0;
            while(n>0){
                int curr=n%10;
                n=n/10;
                sum+=curr*curr;
            }
            n=sum;
            
        }
        return true;
    }
};