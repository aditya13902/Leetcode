class Solution {
public:
    int arrangeCoins(int n) {
        int row=1;
        int cnt=0;
        while(n){
            if(n>=row){
                n-=row;
                row++;
                cnt++;
            }
            else{
                break;
            }
        }
        return cnt;
    }
};