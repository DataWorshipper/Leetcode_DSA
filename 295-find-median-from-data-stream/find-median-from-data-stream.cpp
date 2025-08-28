class MedianFinder {
public:
priority_queue<double>left;
priority_queue<double,vector<double>,greater<double>>right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(left.empty()||num<left.top())
        {
            left.push(num);
        }
        else
        right.push(num);
        if(left.size()>right.size()+1)
        {
            double a=left.top();
            left.pop();
            right.push(a);
        }
          if(left.size()+1<right.size())
        {
            double b=right.top();
            right.pop();
            left.push(b);
        }



    }
    
    double findMedian() {
        
        if(left.size()==right.size())
        {
            return ((double)left.top()+(double)right.top())/2.0;
        }
       else if (left.size() > right.size())
    return left.top();
else
    return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */