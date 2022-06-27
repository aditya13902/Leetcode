class MapSum {
public:
    unordered_map<string,int>mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key]=val;
    }
    
    int sum(string prefix) {
        int add=0;
        for(auto it:mp){
            string str=it.first;
            int n=prefix.size();
            if(str.substr(0,n)==prefix){
                add+=it.second;
            }
        }
        return add;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */