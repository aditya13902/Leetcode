class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        // sort(arr.begin(),arr[])
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0 && mp[arr[i]*2]){
                return true;
            }
        }
        if(mp[0]>1){
            return true;
        }
        return false;
    }
};