class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt0=0;
        int cnt1=0;
        int n=students.size();
        for(auto ele:students){
            if(ele==0) cnt0++;
            else cnt1++;
        }
        for(int i=0;i<sandwiches.size();i++){
            if(sandwiches[i]==0){
                if(cnt0==0){
                    return n;
                }
                cnt0--;
                n--;
            }
            else{
                if(cnt1==0){
                    return n;
                }
                cnt1--;
                n--;
            }
        }
        return 0;
    }
};