class FreqStack {
public:
    unordered_map<int, stack<int>> freqStack;
    unordered_map<int, int> freq;
    int maxFreq;

    FreqStack() {
        maxFreq = 0;
        
    }
    
    void push(int val) {

        freq[val]+=1;
        freqStack[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);
        
    }
    
    int pop() {

        int val = freqStack[maxFreq].top(); freqStack[maxFreq].pop();
        freq[val] -= 1;
        
        if(freqStack[maxFreq].empty()) maxFreq--;     
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */