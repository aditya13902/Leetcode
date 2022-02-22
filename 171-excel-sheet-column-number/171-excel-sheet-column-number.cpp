class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res=0;
        for(char ch:columnTitle){
            int ele=ch-'A'+1;
            cout<<ch-'A'+1<<endl;
            res=res*26+ele;
        }
        return res;
    }
};