class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long int,int>mp;
        for(auto num:nums1){
            mp[num*1LL*num*1LL]++;
        }
        int cnt=0;
        for(int i=0;i<nums2.size();i++){
            for(int j=i+1;j<nums2.size();j++){
                if(mp[nums2[i]*1LL*nums2[j]*1LL]){
                    // cout<<nums2[i]<<" "<<nums2[j]<<endl;
                    cnt+=mp[nums2[i]*1LL*nums2[j]*1LL];
                }
            }
        }
        mp.clear();
        // unordered_map<int,int>mp;
        swap(nums1,nums2);
        for(auto num:nums1){
            mp[num*1LL*num*1LL]++;
        }
        // cnt=0;
        for(int i=0;i<nums2.size();i++){
            for(int j=i+1;j<nums2.size();j++){
                if(mp[nums2[i]*1LL*nums2[j]*1LL]){
                    // cout<<nums2[i]<<" "<<nums2[j]<<endl;
                    cnt+=mp[nums2[i]*1LL*nums2[j]*1LL];
                }
            }
        }
        return cnt;
    }
};