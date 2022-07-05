class Solution {
public:
    int totalFruit(vector<int>& a) {
        int i=0, count=0, k=2, maxLen=0;
        unordered_map<int, int> m;

        for(int j=0; j<a.size(); j++){
            m[a[j]]++;
            if(m[a[j]] == 1) count++;
            if(count > k){
                while(count>k){
                    m[a[i]]--;
                    if(m[a[i]] == 0) count--;
                    i++;
                }
            }
            maxLen = max(j-i+1, maxLen);
        }
        return maxLen;
    }
}; 