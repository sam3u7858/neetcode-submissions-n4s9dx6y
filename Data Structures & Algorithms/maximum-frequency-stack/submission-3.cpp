class FreqStack {
public:
    int max_freq;
    unordered_map<int, stack<int>> freqs;
    unordered_map<int, int> freq;

    FreqStack() {
        max_freq = 0;
        
    }
    
    void push(int val) {
        freq[val]+=1;
        int fq = freq[val];
        max_freq = max(max_freq, freq[val]);
        freqs[fq].push(val);
        
    }
    
    int pop() {
        
        int tmp = freqs[max_freq].top();
        freqs[max_freq].pop();
        freq[tmp] -= 1;
        if(freqs[max_freq].empty()) max_freq--;

        return tmp;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */