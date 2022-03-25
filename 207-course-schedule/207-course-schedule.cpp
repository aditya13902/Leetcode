class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>ind(numCourses,0);
        for(auto vec:prerequisites){
            adj[vec[1]].push_back(vec[0]);
            ind[vec[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(ind[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(q.size()){
            int x=q.front();
            q.pop();
            cnt++;
            for(auto ele:adj[x]){
                ind[ele]--;
                if(ind[ele]==0){
                    q.push(ele);
                }
            }
        }
        return cnt==numCourses;
    }
};