class cmp{
public:
    bool operator()(vector<int>&t1,vector<int>&t2){
        return t1[1]<t2[1];
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        sort(trips.begin(),trips.end(),cmp());
        int curr=0;
        for(int i=0;i<trips.size();i++){
            
            while(pq.size() && pq.top().first<=trips[i][1]){
                curr-=pq.top().second;
                pq.pop();
            }
            pq.push({trips[i][2],trips[i][0]});
            curr+=trips[i][0];
            if(curr>capacity) return false;
        }
        return true;
    }
};