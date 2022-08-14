class Solution {
public:
    int twoEggDrop(int n) {
        int tmp=1;
        int cnt=0;
        while(n>0){
            n-=tmp;
            cnt++;
            tmp++;
        }
        return cnt;
    }
};