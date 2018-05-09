class MinStack {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int> > min_heap,poped;
    stack<int> s;
    
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        min_heap.push(x);
    }
    
    void pop() {
        poped.push(s.top());
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        while(poped.size() && min_heap.top() == poped.top()) {
            poped.pop();
            min_heap.pop();
        }
        return min_heap.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */