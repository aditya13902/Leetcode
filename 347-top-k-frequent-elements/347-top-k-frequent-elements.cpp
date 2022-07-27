class Solution {
public:
    unordered_map<int,int>mp;
    int quickselect(vector<int>&arr,int l,int r,int k){
        int pivot=arr[r];
        int idx=l;
        // cout<<r<<endl;
        for(int i=l;i<r;i++){
            if(mp[arr[i]]>=mp[pivot]){
                swap(arr[i],arr[idx++]);
                // idx++;
            }
        }
        swap(arr[idx],arr[r]);
        // cout<<arr[r]<<endl;
        if(idx>k) return quickselect(arr,l,idx-1,k);
        else if(idx<k) return quickselect(arr,idx+1,r,k);
        else return idx;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>arr;
        for(auto ele:nums){
            if(mp[ele]==0) arr.push_back(ele);
            mp[ele]++;
        }
        k--;
        int idx=quickselect(arr,0,arr.size()-1,k);
        vector<int>vec;
        for(int i=0;i<=idx;i++) vec.push_back(arr[i]);
        
        return vec;
            
    }
};
// 5 3 1 73