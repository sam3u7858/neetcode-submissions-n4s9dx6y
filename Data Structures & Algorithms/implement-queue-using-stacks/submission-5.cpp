class MyQueue {
public:
    stack<int> inS;
    stack<int> outS;
    MyQueue() {
        
    }
    
    void push(int x) {
        inS.push(x);
    }
    
    int pop() {
        int val = peek();
        outS.pop();
        return val;
        
    }
    
    int peek() {
        if(outS.empty()){
            while(!inS.empty()){
                outS.push(inS.top());
                inS.pop();
            }
        }
        return outS.top();
    }
    
    bool empty() {
        return inS.empty() && outS.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */