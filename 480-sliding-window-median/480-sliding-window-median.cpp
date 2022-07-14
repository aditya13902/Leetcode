class Solution {
public:
    multiset<int>mxh;
    multiset<int>mnh;
    vector<double>ans;
    void balance(){
        if(mxh.size()>mnh.size()+1){
            mnh.insert(*(--mxh.end()));
            mxh.erase((--mxh.end()));
        }
        else if(mnh.size()>mxh.size()){
            mxh.insert(*(mnh.begin()));
            mnh.erase(mnh.begin());
        }
    }
    void insert(int ele){
        if(mxh.size()==0 || *(--mxh.end())>=ele){
            mxh.insert(ele);
        }
        else{
            mnh.insert(ele);
        }
        balance();
    }
    void erase(int ele){
        if(mxh.find(ele)!=mxh.end()){
            mxh.erase(mxh.find(ele));
        }
        else{
            mnh.erase(mnh.find(ele));
        }
        balance();
    }
    double median(){
        if(mxh.size()==mnh.size()){
            int ele1=*(--mxh.end());
            int ele2=*(mnh.begin());
            return ((double)ele1+(double)ele2)/2.0;
        }
        else{
            int ele=*(--mxh.end());
            return ele;
        }
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int l=0;
        int r=0;
        while(r<=nums.size()){
            if(r>=k){
                ans.push_back(median());
                erase(nums[l]);
                l++;
            }
            if(r<nums.size()){
                insert(nums[r]);
            }
            r++;
        }
        return ans;
    }
};