class MedianFinder {
public:
    priority_queue<double>maxheap;
    priority_queue<double,vector<double>,greater<double>>minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.size()==0 || maxheap.top()>=num){
            maxheap.push(num);
            if(maxheap.size()>minheap.size()+1){
                minheap.push(maxheap.top());
                maxheap.pop();
            }    
        }
        else{
            minheap.push(num);
            if(minheap.size()>maxheap.size()){
                // cout<<minheap.top()<<endl;
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
        // if(maxheap.size()){
        //     cout<<"1"<<" "<<maxheap.top()<<endl;
        // }
        // if(minheap.size()){
        //     cout<<"2"<<" "<<minheap.top()<<endl;
        // }
        
        
    }
    
    double findMedian() {
        if(maxheap.size()==minheap.size()){
            return (minheap.top()+maxheap.top())/2.0;
        }
        return maxheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */