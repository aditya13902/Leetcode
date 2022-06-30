class Solution {
public:
    // static bool cmp(vector<pair<int,int)
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double,double>>car;
        for(int i=0;i<position.size();i++){
            car.push_back({position[i],speed[i]});
        }
        sort(car.begin(),car.end());
        stack<double>st;
        for(int i=car.size()-1;i>=0;i--){
            auto [p,s]=car[i];
            double t=(target-p)/s;
            int f=0;
            if(st.size() && st.top()>=t){
                f=1;
            }
            if(!f){
                st.push(t);
            }
        }
        return st.size();
        
    }
};
// 