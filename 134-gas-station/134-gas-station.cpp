class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumgas=0;
        int sumcost=0;
        for(auto ele:gas){
            sumgas+=ele;
        }
        for(auto ele:cost){
            sumcost+=ele;
        }
        if(sumgas<sumcost){
            return -1;
        }
        int tot=0;
        int idx=0;
        for(int i=0;i<gas.size();i++){
            tot+=(gas[i]-cost[i]);
            if(tot<0){
                tot=0;
                idx=i+1;
            }
        }
        return idx;
    }
};