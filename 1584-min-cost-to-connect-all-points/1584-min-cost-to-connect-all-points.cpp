class Solution {
public:
    vector<int>par;
    int find(int i){
        if(par[i]==i){
            return i;
        }
        return par[i]=find(par[i]);
    }
    void Union(int a,int b){
        a=find(a);
        b=find(b);
        par[b]=a;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                pq.push(vector<int>{abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]),i,j});
            }
        }
        int cnt=0;
        int n=points.size();
        par.resize(n);
        // map<vector<int>,int>mp;
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        int ans=0;
        while(cnt<n-1){
            auto curr=pq.top();
            pq.pop();
            if(find(curr[1])!=find(curr[2])){
                Union(curr[1],curr[2]);
                ans+=curr[0];
                cnt++;
            }
        }
        return ans;
    }
};