class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(auto str:wordList){
            st.insert(str);
        }
        queue<string>q;
        q.push(beginWord);
        int cnt=1;
        while(q.size()){
            int l=q.size();
            while(l--){
                auto curr=q.front();
                q.pop();
                if(curr==endWord) return cnt;
                for(int i=0;i<curr.size();i++){
                    for(char ch='a';ch<='z';ch++){
                        char pos=curr[i];
                        curr[i]=ch;
                        if(st.find(curr)!=st.end()){
                            st.erase(curr);
                            q.push(curr);
                        }
                        curr[i]=pos;
                    }
                }
            }
            cnt++;
        }
        return 0;
    }
};