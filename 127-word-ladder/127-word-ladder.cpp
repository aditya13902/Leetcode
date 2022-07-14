class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(beginWord);
        // insert into set (from word list)
        unordered_set<string>st;
        for(auto str:wordList) st.insert(str);
        
        if(st.find(endWord)==st.end()) return 0;
        
        int cnt=0;
        while(q.size()){ // simple bfs
            int len=q.size();
            while(len--){
                auto curr=q.front();
                q.pop();
                if(curr==endWord) return cnt+1;
                for(int i=0;i<curr.size();i++){
                    string tmp=curr;
                    for(char ch='a';ch<='z';ch++){
                        tmp[i]=ch;
                        if(tmp==curr) continue;
                        
                        if(st.find(tmp)!=st.end()){
                            st.erase(tmp);
                            q.push(tmp);
                        }
                    }
                }
            }
            cnt++;
        }
        return 0;
    }
};