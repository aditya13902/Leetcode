class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        unordered_map<long,long>mp;
        long res=0;
        long mod=pow(10,9)+7;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]) continue;
                
                mp[arr[i]]=(mp[arr[i]]+mp[arr[i]/arr[j]]*mp[arr[j]])%mod;
            }
            res=(res+mp[arr[i]])%mod;
        }
        return res;
    }
};