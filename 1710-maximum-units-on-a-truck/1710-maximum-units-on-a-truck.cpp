class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int tot=0;
        int i=0;
        while(truckSize && i<boxTypes.size()){
            if(boxTypes[i][0]<=truckSize){
                truckSize-=boxTypes[i][0];
                tot+=boxTypes[i][1]*boxTypes[i][0];
                i++;
            }
            else{
                tot+=boxTypes[i][1]*truckSize;
                truckSize=0;
            }
        }
        return tot;
    }
};