class Solution {
public:
    int minSwaps(string s) {
        int mx=0;
        int curr=0;
        for(auto ch:s){
            if(ch==']') curr++;
            else curr--;
            mx=max(mx,curr);
        }
        return (mx+1)/2;
    }
};