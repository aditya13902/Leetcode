class NumArray {
public:
    int n;
    vector<int>seg;
    void build(int index,int low,int high,vector<int>&nums)
    {
        if(low==high)
        {
            seg[index]=nums[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*index+1,low,mid,nums);
        build(2*index+2,mid+1,high,nums);
        seg[index]=seg[2*index+1]+seg[2*index+2];
    }
    int query(int index,int low,int high,int l,int r)
    {
        if(low>=l && high<=r)
        {
            return seg[index];
        }
        if(high<l || low>r)
            return 0;
        int mid=(low+high)/2;
        int left=query(2*index+1,low,mid,l,r);
        int right=query(2*index+2,mid+1,high,l,r);
        return left+right;
    }
    void up(int index,int low,int high,int value,int idx)
    {
        if(low>idx || high<idx){
            return;
        }
        if(low==high)
        {
            if(low==idx){
                seg[index]=value;
            }
            return;
        }
        int mid=(low+high)/2;
        up(2*index+1,low,mid,value,idx);
        up(2*index+2,mid+1,high,value,idx);
        seg[index]=seg[2*index+1]+seg[2*index+2];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        if(n==0)
            return ;
        seg.resize(4*n,0);
        build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        up(0,0,n-1,val,index);
    }
    
    int sumRange(int i, int j) {
        return query(0,0,n-1,i,j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */