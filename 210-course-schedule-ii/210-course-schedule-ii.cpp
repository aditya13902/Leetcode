class Solution {
public:
    stack<int>st;
    vector<int>vis;
    bool helper(vector<vector<int>>&adj,int i,unordered_set<int>&s){
        if(s.find(i)!=s.end()){
            return false;
        }
        if(vis[i]){
            return true;
        }
        vis[i]=1;
        s.insert(i);
        for(auto ele:adj[i]){
            if(!helper(adj,ele,s)) return false;
        }
        s.erase(i);
        st.push(i);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto vec:prerequisites){
            adj[vec[1]].push_back(vec[0]);
        }
        vector<int>ans;
        // int col=1;
        vis.resize(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                unordered_set<int>s;
                if(!helper(adj,i,s)) return ans;
                // col++;
                
            }
        }
        // for(auto ele:vis){
        //     cout<<ele<<endl;
        // }
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};