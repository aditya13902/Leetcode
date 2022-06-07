class Solution {
public:
    unordered_map<int,int>mp;
    int minDays(int n) {
        if(n==0 || n==1){
            return n;
        }
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }
        int path1=1+(n%2)+minDays(n/2);
        int path2=1+(n%3)+minDays(n/3);
        return mp[n]=min(path1,path2);
    }
};