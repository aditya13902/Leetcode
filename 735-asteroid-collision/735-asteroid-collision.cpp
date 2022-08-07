class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto ele:asteroids){
            int f=1;
            while(st.size() && (ele<0 && st.top()>0)){
                if(abs(ele)>abs(st.top())){
                    st.pop();
                }
                else if(abs(ele)==abs(st.top())){
                    f=0;
                    st.pop();
                    break;
                }
                else{
                    f=0;
                    break;
                }
            }
            if(f){
                st.push(ele);
            }
            
        }
        vector<int>vec;
        while(st.size()){
            vec.push_back(st.top());
            st.pop();
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};