class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        return v1[0]<v2[0];
    }
    long double help(long double x1, long double y1, long double x2, long double y2){
        return (y2 - y1) / (x2 - x1);
    }
    int minimumLines(vector<vector<int>>& vec) {
        
        long double slope;
        int cnt=0;
        sort(vec.begin(),vec.end(),cmp);
        long double prevx=vec[0][0];
        long double prevy=vec[0][1];
        // for(auto ele:vec){
        //     cout<<ele[0]<<" "<<ele[1]<<endl;
        // }
        // i/
        for(int i=1;i<vec.size();i++){
            if(i==1){
                slope=help(prevx,prevy,vec[i][0],vec[i][1]);
                // cout<<slope<<endl;
                cnt++;
            }
            else{
                long double sn=help(prevx,prevy,vec[i][0],vec[i][1]);
                // cout<<sn<<endl;
                if(sn!=slope){
                    cnt++;
                    slope=sn;
                }
            }
            // cout<<vec[i][0]<<" "<<vec[i][1]<<endl;
            prevx=vec[i][0];
            prevy=vec[i][1];
        }
        return cnt;
    }
};


// 12,49   25,7  30,33  69,13    95,36 