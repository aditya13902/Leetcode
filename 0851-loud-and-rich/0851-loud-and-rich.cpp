class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>adj(quiet.size());
        vector<int>indeg(n,0);
        for(auto vec:richer){
            adj[vec[0]].push_back(vec[1]);
            indeg[vec[1]]++;
        }
        queue<int>q;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
            ans[i]=i;
        }
        vector<int>vec;
        while(q.size()){
            auto top=q.front();
            q.pop();
            vec.push_back(top);
            // cout<<top<<" ";
            for(auto ele:adj[top]){
                indeg[ele]--;
                if(quiet[ans[ele]]>quiet[ans[top]]){
                    // cout<<ele<<" by "<<top<<endl;
                    ans[ele]=ans[top];
                }
                if(indeg[ele]==0){
                    q.push(ele);
                }
            }
            
        }
        return ans;
        
    }
};
// 0 -- 1
// 1 -- 2
// 2 -- 0
// 3 -- 3
// 4 -- 0
// 5 -- 0
// 6 -- 0
// 7 -- 1