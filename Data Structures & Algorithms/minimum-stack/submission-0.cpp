class MinStack {
public:
    stack<int> cars;
    stack<int> minstack;

    MinStack() {
        // 不需要在這裡重新宣告 stack，只要建構子不做任何事即可
    }

    void push(int val) {
        cars.push(val);
        if (!minstack.empty())
            minstack.push(min(val, minstack.top()));
        else
            minstack.push(val);
    }

    void pop() {
        cars.pop();
        minstack.pop();
    }

    int top() {
        return cars.top();
    }

    int getMin() {
        return minstack.top();
    }
};
