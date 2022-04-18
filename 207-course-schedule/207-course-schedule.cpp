class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int>indeg(n,0);
        for(auto ele:pre){
            indeg[ele[1]]++;
        }
        vector<vector<int>>adj(n);
        for(auto ele:pre){
            adj[ele[0]].push_back(ele[1]);
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(q.size()){
            int top=q.front();
            q.pop();
            for(auto ele:adj[top]){
                if(indeg[ele]==0){
                    continue;
                }
                indeg[ele]--;
                if(indeg[ele]==0){
                    q.push(ele);
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