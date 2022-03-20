class Solution {
public:
    int helper(vector<int>& tops, vector<int>& bottoms,bool flag,int val,int idx){
        if(idx>=tops.size()){
            return 0;
        }
        if(flag){
            if(tops[idx]==val){
                return helper(tops,bottoms,flag,val,idx+1);
            }
            else if(bottoms[idx]==val){
                return 1+helper(tops,bottoms,flag,val,idx+1);
            }
            else{
                return 1000000;
            }
        }
        else{
            if(bottoms[idx]==val){
                return helper(tops,bottoms,flag,val,idx+1);
            }
            else if(tops[idx]==val){
                return 1+helper(tops,bottoms,flag,val,idx+1);
            }
            else{
                return 1000000;
            }
        }
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int a=helper(tops,bottoms,true,tops[0],1);
        int b=1+helper(tops,bottoms,true,bottoms[0],1);
        int c=1+helper(tops,bottoms,false,tops[0],1);
        int d=helper(tops,bottoms,false,bottoms[0],1);
        // cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        return min(min(a,b),min(c,d))>tops.size() ?-1 :min(min(a,b),min(c,d));
    }
};