class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        unordered_map<int,vector<pair<string,int>>>mp;
        int k=0;
        int n=nums[0].size();
        while(k!=nums[0].size()){
            for(int i=0;i<nums.size();i++){
                mp[n-k].push_back({nums[i].substr(k),i});
            }    
            k++;
        }
        for(auto &it:mp){
            auto &vec=it.second;
            sort(vec.begin(),vec.end());
        }
        vector<int>ans;
        for(auto vec:queries){
            int ele=mp[vec[1]][vec[0]-1].second;
            ans.push_back(ele);
        }
        return ans;
    }
};