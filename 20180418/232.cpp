class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        ths.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> tmp;
        while(ths.size()) {
            tmp.push(ths.top());
            ths.pop();
        }
        int res = tmp.top();
        tmp.pop();
        while(tmp.size()) {
            ths.push(tmp.top());
            tmp.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> tmp;
        while(ths.size()) {
            tmp.push(ths.top());
            ths.pop();
        }
        int res = tmp.top();
        while(tmp.size()) {
            ths.push(tmp.top());
            tmp.pop();
        }
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return ths.empty();
    }
private:
    stack<int> ths;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */