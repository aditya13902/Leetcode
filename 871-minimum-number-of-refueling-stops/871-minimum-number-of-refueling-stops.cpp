class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int curr=startFuel;
        int cnt=0;
        int i=0;
        int n=stations.size();
        while(curr<target){
            while(i<n && curr>=stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.size()==0) return -1;
            curr+=pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};