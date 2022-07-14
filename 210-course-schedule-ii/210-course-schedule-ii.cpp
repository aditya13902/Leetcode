class Solution {
public:
    stack<int>st;
    vector<int>vis;
    bool helper(int v,vector<vector<int>>&adj,unordered_set<int>&mp){
        if(mp.find(v)!=mp.end()) return false;
        if(vis[v]) return true;
        mp.insert(v);
        vis[v]=1;
        for(auto ele:adj[v]){
            if(helper(ele,adj,mp)==false) return false;

        }
        mp.erase(v);
        st.push(v);
        return true;
    }
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<vector<int>>adj(num);
        for(auto vec:pre){
            adj[vec[1]].push_back(vec[0]);
        }
        vector<int>ans;
        vis.resize(num,0);
        for(int i=0;i<num;i++){
            if(vis[i]==0){
                unordered_set<int>mp;
                if(!helper(i,adj,mp)) return ans;
            }
        }
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};