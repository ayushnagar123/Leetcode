class CustomStack {
public:
    int limit;
    stack<int> s;
    stack<int> temp;
    CustomStack(int maxSize) {
        limit = maxSize;
    }
    
    void push(int x) {
        if(s.size() < limit){
            s.push(x);
        }
    }
    
    int pop() {
        if(s.empty()){
            return -1;
        }
        int top = s.top();
        s.pop();
        return top;
    }
    
    void increment(int k, int val) {
        while(!temp.empty()){
            temp.pop();
        }
        while(!s.empty()){
            temp.push(s.top());
            s.pop();
        }
        int v;
        while(!temp.empty() && k--){
            v = temp.top();
            temp.pop();
            s.push(v + val);
        }
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }
};

// Runtime: 76 ms, faster than 8.00% of C++ online submissions for Design a Stack With Increment Operation.
// Memory Usage: 29.7 MB, less than 7.62% of C++ online submissions for Design a Stack With Increment Operation.

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
