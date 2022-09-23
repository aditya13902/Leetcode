const long mod=1e9+7;
class Solution {
public:
    int last(int n){
        int l=0;
        while(n>0){
            n=n>>1;
            l++;
        }
        return l;
    }
    int concatenatedBinary(int n) {
        long ans=0;
        long len=0;
        for(int i=1;i<=n;i++){
            int shift=last(i);
            ans=(ans<<shift)%mod;
            ans=(ans+i)%mod;
        }
        return ans;
    }
};