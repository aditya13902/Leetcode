class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string>q;
        q.push(start);
        int d=0;
        map<string,int>mp;
        while(q.size()){
            int l=q.size();
            for(int i=0;i<l;i++){
                auto curr=q.front();
                q.pop();
                if(mp[curr]) continue;
                mp[curr]=1;
                if(curr==end) return d;
                for(auto str:bank){
                    int cnt=0;
                    for(int i=0;i<8;i++){
                        if(str[i]!=curr[i]){
                            cnt++;
                        }
                    }
                    if(cnt==1){
                        // cout<<str<<endl;
                        q.push(str);
                    }
                }
               
            }
            d++;
        }
        return -1;
    }
};