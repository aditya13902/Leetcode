class Solution {
public:
    int factorial(int n){
        if(n==0) return 1;
        return n*factorial(n-1);
    }
    string getPermutation(int n, int k) {
        string s="";
        vector<int>vec;
        for(int i=1;i<=n;i++){
            vec.push_back(i);
        }
        k--;
        while(vec.size()){
            int fact=factorial(n-1);
            int idx=(k/fact);
            s+=(vec[idx]+'0');
            k-=idx*fact;
            vec.erase(vec.begin()+idx);
            n--;
        }
        return s;
    }
};