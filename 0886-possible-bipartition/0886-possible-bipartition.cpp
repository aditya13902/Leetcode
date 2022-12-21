class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto ele:dislikes){
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }
        vector<int>color(n+1,0);
        for(int i=1;i<=n;i++){
            if(color[i]==0){
                queue<int>q;
                q.push(i);
                color[i]=1;
                while(q.size()){
                    auto curr=q.front();
                    q.pop();
                    int col=color[curr];
                    for(auto ele:adj[curr]){
                        if(color[ele]==col){
                            return false;
                        }
                        else if(color[ele]==0){
                            color[ele]=-col;
                            q.push(ele);
                        }
                    }
                }
            }
        }
        return true;
    }
};