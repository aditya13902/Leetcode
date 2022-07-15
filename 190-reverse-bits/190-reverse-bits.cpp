class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int j=1;
        while(n){
            if(n&1){
                ans|=(1<<(32-j));
            }
            j++;
            n=n>>1;
        }
        return ans;
    }
};