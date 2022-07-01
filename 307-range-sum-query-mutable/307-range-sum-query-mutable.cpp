class NumArray {
public:
    vector<int>bit;
    vector<int>vec;
    int n;
    int sum(int i){
        int ans=0;
        for(;i>0;i-=(i&-i)){
            ans+=bit[i];
        }
        // cout<<ans<<endl;
        return ans;
    }
    void add(int i,int val){
        for(;i<=n;i+=(i&-i)){
            bit[i]+=val;
        }
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        vec=nums;
        bit.resize(n+1,0);
        for(int i=1;i<=n;i++){
            add(i,nums[i-1]);
        }
    }
    
    void update(int index, int val) {
        int x=val-vec[index];
        // cout<<x<<endl;
        add(index+1,x);
        vec[index]=val;
    }
    
    int sumRange(int left, int right) {
        return sum(right+1)-sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */