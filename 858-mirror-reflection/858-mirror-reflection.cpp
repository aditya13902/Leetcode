class Solution {
public:
    int mirrorReflection(int p, int q) {
        int k=1;
        while((q*k)%p) k++;
        
        int n=(q*k)/p;
        
        if(n%2 && k%2) return 1;
        else if(n%2==0 && k%2) return 0;
        else return 2;
        
    }
};