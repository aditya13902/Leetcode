class MedianFinder {
public:
    priority_queue<int>maxpq;
    priority_queue<int,vector<int>,greater<int>>minpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxpq.size()==0 || maxpq.top()>=num){
            maxpq.push(num);
        }
        else{
            minpq.push(num);
        }
        
        if(maxpq.size()>minpq.size()+1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if(maxpq.size()<minpq.size()){
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        if(minpq.size()==maxpq.size()){
            return minpq.top()/2.0+maxpq.top()/2.0;
        }
        return maxpq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */