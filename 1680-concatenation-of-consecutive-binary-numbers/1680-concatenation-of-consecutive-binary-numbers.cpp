const long mod=1e9+7;
class Solution {
public:
    int concatenatedBinary(int n) {
        long ans=0;
        long len=0;
        for(int i=1;i<=n;i++){
            if((i&(i-1))==0){
                len++;
            }
            ans=(ans<< len)%mod;
            ans=(ans+i)%mod;
        }
        return ans;
    }
};