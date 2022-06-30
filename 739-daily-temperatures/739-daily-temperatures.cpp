class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.size() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(st.size()==0){
                nge[i]=0;
            }
            else{
                nge[i]=st.top()-i;
            }
            st.push(i);
        }
        return nge;
        
    }
};