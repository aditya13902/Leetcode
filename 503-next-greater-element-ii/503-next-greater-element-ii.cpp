class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        vector<int>ans(n,-1);
        st.push(0);
        for(int i=1;i<2*n;i++){
            while(st.size() && nums[i%n]>nums[st.top()]){
                ans[st.top()]=nums[i%n];
                st.pop();

            }
            if(i<n){
                st.push(i);
            }
            
        }
        return ans;
        
    }
};