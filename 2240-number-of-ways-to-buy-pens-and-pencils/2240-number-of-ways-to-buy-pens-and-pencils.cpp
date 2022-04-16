class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long ans=0;
        
        int val=0;
        
        for(int x=0;;x++)
        {
            val=total-cost1*x;
            if(val < 0) break;
            ans+= (long)((long)val /(long) cost2)+1;
         
        }
       
         return ans;
        
    }
};