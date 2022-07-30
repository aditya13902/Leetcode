class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>col(graph.size());
        for(int i=0;i<graph.size();i++){
            if(col[i]) continue;
            queue<int>q;
            q.push(i);
            col[i]=1;
            while(q.size()){
                int l=q.size();
                while(l--){
                    int top=q.front();
                    q.pop();
                    for(auto ele:graph[top]){
                        if(col[ele]!=0){
                            if(col[ele]==col[top]) return false;
                            continue;
                        }
                        col[ele]=-col[top];
                        q.push(ele);
                    }
                }
            }
        }
        return true;
    }
};