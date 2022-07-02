class Solution {
public:
    int N=1e9+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long long diffrow=0;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        horizontalCuts.push_back(h);
        horizontalCuts.insert(horizontalCuts.begin(),0);
        verticalCuts.push_back(w);
        verticalCuts.insert(verticalCuts.begin(),0);
        // cout<<"row :"<<endl;
        for(int i=0;i<horizontalCuts.size()-1;i++){
            // cout<<horizontalCuts[i+1]-horizontalCuts[i]<<endl;
            diffrow=max(diffrow,(long long)horizontalCuts[i+1]-(long long)horizontalCuts[i]);
        }
        // cout<<"col /:"<<endl;
        long long  diffcol=0;
        for(int i=0;i<verticalCuts.size()-1;i++){
            // cout<<verticalCuts[i+1]-verticalCuts[i]<<endl;
            diffcol=max(diffcol,(long long)verticalCuts[i+1]-(long long)verticalCuts[i]);
        }
        return ((diffrow%N)*(diffcol%N)%(N));
    }
};