class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int consecutive_days = 1;
        while(!st.empty() && st.top().first <= price){
            consecutive_days += st.top().second;
            st.pop();
        }
        
        st.push({price, consecutive_days});
        return consecutive_days;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */