class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int freq) {
        for(int i=0;i<=arr.size()-m;i++){
            vector<int>vec;
            for(int j=i;j<i+m;j++){
                vec.push_back(arr[j]);
            }
            int cnt=0;
            for(int j=i;j<=arr.size()-m;j+=m){
                int idx=0;
                for(int k=j;k<j+m;k++){
                    if(arr[k]==vec[idx]){
                        idx++;
                    }
                    else{
                        break;
                    }
                }
                if(idx==m){
                    cnt++;
                }
                else{
                    break;
                }
            }
            if(cnt>=freq){
                return true;
            }
        }
        return false;
    }
};