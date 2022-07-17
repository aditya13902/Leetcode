class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>vec;
        for(int i=0;i<profits.size();i++){
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(),vec.end());
        int i=0;
        int n=profits.size();
        priority_queue<int>pq;
        while(k--){
            while(i<n && w>=vec[i].first){
                pq.push(vec[i].second);
                i++;
            } 
            if(pq.size()){
                w+=pq.top();
                pq.pop();
            }
        }
        return w;
    }
};