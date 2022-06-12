class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(auto ele:spells){
            long long val=success/ele;
            if(success%ele){
                auto it=upper_bound(potions.begin(),potions.end(),val);
                ans.push_back(potions.end()-it);
            }
            else{
                auto it=lower_bound(potions.begin(),potions.end(),val);
                ans.push_back(potions.end()-it);
            }
            // ans.push_back(potions.end()-it);
        }
        return ans;
    }
};