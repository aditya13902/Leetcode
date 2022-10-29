class Solution {
public:
    int earliestFullBloom(vector<int>& plt, vector<int>& grw) {
        vector<pair<int,int>>vec;
        for(int i=0;i<plt.size();i++){
            vec.push_back({grw[i],plt[i]});
        }
        sort(vec.rbegin(),vec.rend());
        int prev=0;
        int ans=0;
        for(int i=0;i<vec.size();i++){
            ans=max(ans,prev+vec[i].second+vec[i].first);
            prev=prev+vec[i].second;
            // cout<<prev<<endl;
        }
        return ans;
        
    }
};
// p p p g g
//       p p g
//           p p g
//               p g


// p p p p g g g
//         p g g
//           p p p g
//               