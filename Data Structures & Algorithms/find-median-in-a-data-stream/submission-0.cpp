class MedianFinder {

private:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;
    

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (lower.empty() || num <= lower.top())
            lower.push(num);
        else
            upper.push(num);

        this->rebalance();
        return;

    }
    void rebalance() {
        if (lower.size() > upper.size() + 1) {
            upper.push(lower.top());
            lower.pop();
        } else if (upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if (lower.size() == upper.size()){
            double fisrt = lower.top();
            double second = upper.top();
            return (fisrt + second) / 2.0;
        }
        else{
            return lower.top() / 1.0 ;
        }
    }
};
