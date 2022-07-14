class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i=0;
        int j=0;
        int happy=0;
        int made_happy=0;
        int mx=0;
        while(j<customers.size()){
            happy+=(!grumpy[j])*customers[j];
            made_happy+=(grumpy[j])*customers[j];
            
            if(j>=minutes){
                made_happy-=(grumpy[i])*customers[i];
                i++;
            }
            mx=max(mx,made_happy);
            j++;
        }
        return mx+happy;
    }
};