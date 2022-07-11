class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char,int>>st;
        int ans=0;
        for(int i=0;i<colors.size();i++){
            if(st.size()==0 || st.top().first!=colors[i]){
                st.push({colors[i],neededTime[i]});
            }
            else{
                if(st.top().second>=neededTime[i]){
                    ans+=neededTime[i];
                }
                else{
                    ans+=st.top().second;
                    st.pop();
                    st.push({colors[i],neededTime[i]});
                }
            }
        }
        return ans;
    }
};