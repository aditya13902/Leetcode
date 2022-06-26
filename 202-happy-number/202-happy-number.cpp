class Solution {
public:
    int solve(int n){
        int sum=0;
        while(n>0){
            int curr=n%10;
            n=n/10;
            sum+=(curr*curr);
        }
        return sum;
    }
    bool isHappy(int n) {
        // int sum=0;
        int slow=n;
        int fast=n;
        do{
            
            slow=solve(slow);
            fast=solve(solve(fast));
            if(fast==1){
                return true;
            }
        }while(slow!=fast);
        return false;
    }
};