class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int>pq;
        int i=0;
        for(;i<heights.size()-1;i++){
            if(heights[i+1]<=heights[i]){
                continue;
            }
            int diff=heights[i+1]-heights[i];
            if(diff<=bricks){
                pq.push(diff);
                bricks-=diff;
            }
            else if(ladders>0){
                if(pq.size()>0){
                    int front=pq.top();
                    if(front>diff){
                        bricks+=front;
                        bricks-=diff;
                        pq.pop();
                        pq.push(diff);
                    }
                }
                ladders--;
            }
            else{
                break;
            }
        }
        return i;
    }
};
// class Solution {
// public:
//     vector<vector<vector<int>>>dp;
//     int reach=0;
//     int helper(vector<int>& heights, int bricks, int ladders,int idx){
//         if(bricks<0 || ladders<0){
//             return 0;
//         }
//         reach=max(reach,idx);
//         if(idx>=heights.size()-1){
//             return 0;
//         }
//         if(dp[idx][bricks][ladders]!=-1){
//             return dp[idx][bricks][ladders];
//         }
//         int ans=0;
//         if(heights[idx+1]<=heights[idx]){
//             ans=helper(heights,bricks,ladders,idx+1);
//         }
//         else{
//             int diff=heights[idx+1]-heights[idx];
//             ans=max(helper(heights,bricks,ladders-1,idx+1),helper(heights,bricks-diff,ladders,idx+1));
//         }
//         return dp[idx][bricks][ladders]=ans;
//     }
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         dp.resize(heights.size(),vector<vector<int>>(bricks+1,vector<int>(ladders+1,-1)));
//         helper(heights,bricks,ladders,0);
//         return reach;
//     }
// };