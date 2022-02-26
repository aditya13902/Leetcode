class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0;
        int cnt10=0;
        // sort(bills.begin(),bills.end());
        for(auto ele:bills){
            if(ele==5){
                cnt5++;
            }
            else if(ele==10){
                if(cnt5<=0){
                    return false;
                }
                cnt5--;
                cnt10++;
            }
            else{
                if(cnt5==0){
                    return false;
                }
                if(cnt10==0){
                    if(cnt5<3){
                        return false;
                    }
                    cnt5-=3;
                    continue;
                }
                cnt5--;
                cnt10--;
            }
        }
        return true;
    }
};