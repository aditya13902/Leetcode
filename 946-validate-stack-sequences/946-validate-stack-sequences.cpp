class Solution {
public:
    // bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    //     stack<int>st;
    //     int i=0;
    //     for(auto ele:pushed){
    //         st.push(ele);
    //         while(st.size()>0 && st.top()==popped[i]){
    //             st.pop();
    //             i++;
    //         }
    //     }
    //     return st.size()==0;
    // }
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0;
        int j=0;
        for(auto ele:pushed){
            pushed[i++]=ele;
            while(i>0 && pushed[i-1]==popped[j]){
                i--;
                j++;
            }
        }
        return i==0;
    }
};