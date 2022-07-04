class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int>candyl(ratings.size(),1);
        for(int i=1;i<ratings.size();i++){
            if(ratings[i-1]<ratings[i]){
                candyl[i]=candyl[i-1]+1;
            }
        }
        vector<int>candyr(ratings.size(),1);
        for(int i=ratings.size()-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                candyr[i-1]=candyr[i]+1;
            }
        }
        int sum=0;
        for(int i=0;i<ratings.size();i++){
            sum+=max(candyl[i],candyr[i]);
        }
        return sum;
    }
};