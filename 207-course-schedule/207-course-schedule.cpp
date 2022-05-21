// 1->4;
// 2->4;
// 3->1;
// 3->2;
class Solution {
public:

    bool canFinish(int n, vector<vector<int>>& req) {
        vector<vector<int>>adj(n);
        for(int i=0;i<req.size();i++){
            adj[req[i][1]].push_back(req[i][0]);
        }
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                // cout<<ele<<" ";
                q.push(i);
            }
        }
        while(q.size()){
            auto ele=q.front();
            q.pop();
            for(auto it:adj[ele]){
                indeg[it]--;
                if(indeg[it]==0){
                    // cout<<it<<" ";
                    q.push(it);
                }
            }
        }
        for(auto ele:indeg){
            if(ele!=0){
                return false;
            }
        }
        return true;
    }
};