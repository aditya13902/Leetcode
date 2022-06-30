class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses,0);
        for(auto vec:prerequisites){
            adj[vec[1]].push_back(vec[0]);
            indeg[vec[0]]++;
        }
        queue<int>q;
        int f=0;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                f=1;
                q.push(i);
            }
        }
        if(!f){
            return false;
        }
        while(q.size()){
            int l=q.size();
            while(l--){
                auto curr=q.front();
                q.pop();
                for(auto ele:adj[curr]){
                    indeg[ele]--;
                    if(indeg[ele]==0){
                        q.push(ele);
                    }
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