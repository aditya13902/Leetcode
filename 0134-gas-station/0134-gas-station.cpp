class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gsum=0;
        int csum=0;
        for(auto ele:gas) gsum+=ele;
        for(auto ele:cost) csum+=ele;
        if(gsum<csum) return -1;
        int sum=0;
        int idx=-1;
        for(int i=0;i<gas.size();i++){
            if(sum<0 || idx==-1){
                idx=i;
                sum=0;
            }
            sum+=gas[i]-cost[i];
        }
        return idx;
    }
};
// -2 -2 -2 3 6