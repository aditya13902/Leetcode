class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        for(int i=0;i<gas.size();i++){
            sum+=(gas[i]-cost[i]);
        }
        if(sum<0){
            return -1;
        }
        int curr=0;
        int idx=0;
        for(int i=0;i<gas.size();i++){
            curr+=gas[i]-cost[i];
            if(curr<0){
                idx=i+1;
                curr=0;
            }
        }
        return idx;
    }
};