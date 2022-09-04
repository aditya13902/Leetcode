class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int i=0;
        long long curr=0;
        int ans=0;
        multiset<int>st;
        for(int j=0;j<chargeTimes.size();j++){
            curr+=runningCosts[j];
            st.insert(chargeTimes[j]);
            while(i<=j && curr*(j-i+1)+*(--st.end())>budget){
                curr-=runningCosts[i];
                st.erase(st.find(chargeTimes[i]));
                i++;
            }
            ans=max(ans,(j-i+1));
        }
        return ans;
    }
};