class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto ch:s){
            mp[ch]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto ele:mp){
            pq.push({ele.second,ele.first});
        }
        string str="";
        while(pq.size()>1){
            auto top1=pq.top();
            pq.pop();
            auto top2=pq.top();
            pq.pop();
            str+=top1.second;
            str+=top2.second;
            top1.first--;
            top2.first--;
            if(top1.first > 0)
                pq.push(top1);
            
            if(top2.first > 0)
                pq.push(top2);
        }
        if(!pq.empty()){
            if(pq.top().first > 1)
                return "";
            
            else
                str+=pq.top().second;
        }
        return str;
    }
};