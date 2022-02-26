class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size()==1){
            return 0;
        }
        int finalpart=(1<<graph.size())-1;
        queue<pair<int,int>>q;
        for(int i=0;i<graph.size();i++){
            q.push({i,1<<i});
        }
        int cnt=0;
        set<pair<int,int>>st;
        while(q.size()){
            int l=q.size();
            cnt++;
            for(int i=0;i<l;i++){
                auto curr=q.front();
                q.pop();
                int node=curr.first;
                int bit=curr.second;
                for(auto ele:graph[node]){
                    int newbit=bit|(1<<ele);
                    if(st.find({ele,newbit})!=st.end()){
                        continue;
                    }
                    st.insert({ele,newbit});
                    if(newbit==finalpart){
                        return cnt;
                    }
                    q.push({ele,newbit});
                }
            }
        }
        return -1;
    }
};