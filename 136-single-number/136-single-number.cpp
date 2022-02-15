class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto ele:nums){
            mp[ele]++;
        }
        for(auto itr:mp){
            if(itr.second==1){
                return itr.first;
            }
        }
        return -1;
    }
};
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_set<int>st;
//         for(auto ele:nums){
//             if(st.find(ele)!=st.end()){
//                 st.erase(ele);
//             }
//             else{
//                 st.insert(ele);
//             }
//         }
//         return *st.begin();
//     }
// };
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         int ans=0;
//         for(auto ele:nums){
//             ans=ans^ele;
//         }
//         return ans;
//     }
// };