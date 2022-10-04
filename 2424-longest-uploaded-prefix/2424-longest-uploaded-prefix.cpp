class LUPrefix {
public:
    vector<int>vec;
    int curr=0;
    LUPrefix(int n) {
        vec.resize(n+1,0);
    }
    
    void upload(int video) {
        vec[video-1]=1;
        while(vec[curr]){
            curr++;
        }
    }
    
    int longest() {
        return curr;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */