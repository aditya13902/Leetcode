class NumArray {
public:
    int n;
    vector<int>seg;
    
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
    
    
    NumArray(vector<int>& nums) {
        n=nums.size();
        if(n==0)
            return ;
        seg.resize(4*n);
        build(0,0,n-1,nums);
        
    }
    
    int sumRange(int i, int j) {
        return query(0,0,n-1,i,j);
        
    }
};