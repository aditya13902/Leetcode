class Solution {
public:
    int nthUglyNumber(int n) {
        set<long>pq;
        pq.insert(1);
        int cnt=1;
        while(true){
            if(cnt==n){
                return *(pq.begin());
            }
            long ele=*(pq.begin());
            // cout<<ele<<endl;
            pq.erase(pq.begin());
            pq.insert(2*ele);
            pq.insert(3*ele);
            pq.insert(5*ele);
            cnt++;
        }
        return -1;
    }
};