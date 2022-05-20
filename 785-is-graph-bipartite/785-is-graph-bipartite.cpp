class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(color[i]==0){
                queue<int>q;
                q.push(i);
                color[i]=1;
                while(q.size()){
                    int l=q.size();
                    while(l--){
                        int top=q.front();
                        q.pop();
                        for(auto ele:graph[top]){
                            if(color[ele]==color[top]){
                                return false;
                            }
                            if(color[ele]!=0){
                                continue;
                            }
                            color[ele]=-color[top];
                            q.push(ele);
                        }
                    }
                }
            }
        }
        return true;
    }
};