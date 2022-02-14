
class Solution {
public:
    string reverseVowels(string s) {
        vector<char>vec;
        for(auto ch:s){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'|| ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
                vec.push_back(ch);
            }
        }
        reverse(vec.begin(),vec.end());
        int i=0;
        for(auto&ch:s){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'|| ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
                ch=vec[i++];
            }
        }
        return s;
    }
};
