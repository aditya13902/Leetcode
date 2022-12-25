#define pb push_back
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        vector<int>sum;
        int curr=0;
        for(auto ele:nums){
            curr+=ele;
            sum.pb(curr);
            // cout<<curr<<endl;
        }
        for(auto ele:queries){
            auto it=upper_bound(sum.begin(),sum.end(),ele);
            if(it==sum.end()){
                ans.pb(nums.size());
            }
            else{
                ans.pb(it-sum.begin());
            }
        }
        return ans;
    }
};