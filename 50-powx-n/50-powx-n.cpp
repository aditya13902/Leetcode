class Solution {
public:
    double helper(double x,int n){
        if(x==0) return 0;
        if(n==0) return 1;
        double subans=helper(x*x,n/2);
        return (n%2)?x*subans:subans;
    }
    double myPow(double x, int n) {
        double ans=helper(x,n);
        if(n<0){
            return 1/ans;
        }
        return ans;
    }
};