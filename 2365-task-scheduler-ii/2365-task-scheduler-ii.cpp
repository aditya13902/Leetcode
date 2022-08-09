class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long t=0;
        unordered_map<int,long long>mp;
        for(int i=0;i<tasks.size();i++){
            if(mp.find(tasks[i])==mp.end()){
                mp[tasks[i]]=t+space+1;
            }
            else{
                t=max(t,mp[tasks[i]]);
                mp[tasks[i]]=t+space+1;
            }
            t++;
        }
        return t;
    }
};
// tasks = [1,2,1,2,3,1], space = 3
// 4 5