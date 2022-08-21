class Solution {
public:
    int mp[100001] = {};
    bool check(string &s,string &p,vector<int>& removable,int k){
        int idx=0;
        memset(mp,0,sizeof(mp));
        for(int i=0;i<k;i++){
            mp[removable[i]]=1;
        }
        for(int i=0;i<s.size() && idx<p.size();i++){
            if(!mp[i] && s[i]==p[idx]){
                idx++;
            }
        }
        return idx==p.size();
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int l=0;
        int r=removable.size();
        int ans=-1;
        while(l<=r){
            int k=l+(r-l)/2;
            if(check(s,p,removable,k)){
                ans=k;
                l=k+1;
            }
            else{
                r=k-1;
            }
        }
        return ans;
    }
};