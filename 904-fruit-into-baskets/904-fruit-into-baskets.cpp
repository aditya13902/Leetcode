class Solution {
public:
    int totalFruit(vector<int>& a) {
        int i=0, count=0, k=2, maxLen=0;
        unordered_map<int, int> m;

        for(int j=0; j<a.size(); j++){
            if(m[a[j]] == 0) count++;
            m[a[j]]++;
            
            while(m.size()>k){
                m[a[i]]--;
                if(m[a[i]] == 0) m.erase(a[i]);
                i++;
            }
            maxLen = max(j-i+1, maxLen);
        }
        return maxLen;
    }
}; 