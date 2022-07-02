class Solution {
public:
    map<pair<int,int>,int> mp;
    int helper(vector<int>&arr1,vector<int>&arr2,int prev,int idx){
        if(idx==arr1.size()){
            return 0;
        }
        if(mp.find({idx,prev})!=mp.end()){
            return mp[{idx,prev}];
        }
        auto it=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
        int ans=1e5;
        if(prev<arr1[idx]){
            ans=min(ans,helper(arr1,arr2,arr1[idx],idx+1));
        }
        if(it<arr2.size()){
            ans=min(ans,helper(arr1,arr2,arr2[it],idx+1)+1);
        }
        return mp[{idx,prev}]=ans;
        
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        int ans= helper(arr1,arr2,INT_MIN,0);
        return ans>=1e5?-1:ans;
    }
};