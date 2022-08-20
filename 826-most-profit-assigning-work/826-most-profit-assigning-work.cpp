class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();
        int m=worker.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({difficulty[i],profit[i]});
        }
        sort(worker.begin(),worker.end());
        sort(vec.begin(),vec.end());
        int i=0;
        int mx=0;
        int ans=0;
        for(auto ele:worker){
            while(i<n && vec[i].first<=ele){
                // i++;
                mx=max(mx,vec[i].second);
                i++;
            }
            // cout<<mx<<endl;
            ans+=mx;
        }
        return ans;
    }
};