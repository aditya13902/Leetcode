class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int>v1;
        string a="";
        for(int i=0;i<version1.size();i++){
            if(version1[i]=='.'){
                v1.push_back(stoi(a));
                a="";
                continue;
            }
            a+=version1[i];
        }
        v1.push_back(stoi(a));
        vector<int>v2;
        string b="";
        for(int i=0;i<version2.size();i++){
            if(version2[i]=='.'){
                v2.push_back(stoi(b));
                b="";
                continue;
            }
            b+=version2[i];
        }
        v2.push_back(stoi(b));
        while(v1.size()!=v2.size()){
            if(v1.size()<v2.size()){
                v1.push_back(0);
            }
            else{
                v2.push_back(0);
            }
        }
        for(int i=0;i<v1.size();i++){
            if(v1[i]>v2[i]){
                return 1;
            }
            else if(v1[i]<v2[i]){
                return -1;
            }
        }
        return 0;
    }
};