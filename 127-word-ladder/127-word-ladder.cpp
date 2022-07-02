class Solution {
public:
    set<string>mp;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto str:wordList){
            mp.insert(str);
        }
        if(mp.find(endWord)==mp.end()){
            return 0;
        }
        queue<string>q;
        q.push(beginWord);
        int cnt=0;
        while(q.size()){
            cnt++;
            int n=q.size();
            while(n--){
                string s=q.front();
                q.pop();
                for(int i=0;i<s.length();i++){
                    string tmp=s;
                    for(int ch='a';ch<='z';ch++){
                        tmp[i]=ch;
                        if(tmp==s){
                            continue;
                        }
                        if(tmp==endWord){
                            return cnt+1;
                        }
                        if(mp.find(tmp)!=mp.end()){
                            q.push(tmp);
                            mp.erase(tmp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};