class MinStack {
public:
    stack<int> st;
    stack<int> helper;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);

        if(!helper.empty() && helper.top()<val){
            helper.push(helper.top());
        }
        else{
            helper.push(val);
        }

        return;

        
    }
    
    void pop() {
        st.pop();
        helper.pop();
        return;
    }
    
    int top() {
        return st.top();
        
        
    }
    
    int getMin() {
       
        return helper.top();
        
        
    }
};
