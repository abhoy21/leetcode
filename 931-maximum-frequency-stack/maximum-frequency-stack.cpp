class FreqStack {
public:
    unordered_map<int, int> freq_map;
    unordered_map<int, stack<int>>freq_stack_map;
    int max_freq;
    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        int freq = ++freq_map[val];

        if(freq >= max_freq)
            max_freq = freq;
        
        freq_stack_map[freq].push(val);
    }
    
    int pop() {
        if(max_freq <= 0)
            return -1;
            
        if(freq_stack_map[max_freq].empty())
            max_freq--;

        int ans = freq_stack_map[max_freq].top();
        freq_stack_map[max_freq].pop();

        freq_map[ans]--;

        return ans;
        
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */