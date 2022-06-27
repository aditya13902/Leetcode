class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int siz=nums.size();
        set<vector<int>>st;
        for(int i=0;i<siz;i++){
            vector<int>subvec;
            int cnt=0;
            for(int j=i;j<siz;j++){
                subvec.push_back(nums[j]);
                if(nums[j]%p==0){
                    if(cnt==k){
                        break;
                    }
                    // break;
                    cnt++;
                }
                st.insert(subvec);
            }
        }
        return st.size();
    }
};