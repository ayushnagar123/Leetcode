class BrowserHistory {
public:
    stack<string> history;
    stack<string> temp;
    BrowserHistory(string homepage) {
        history.push(homepage);
    }
    
    void visit(string url) {
        history.push(url);
        while(!temp.empty()){
            temp.pop();
        }
    }
    
    string back(int steps) {
        while(!(history.size()==1) && steps>0){
            temp.push(history.top());
            history.pop();
            steps--;
        }
        return history.top();
    }
    
    string forward(int steps) {
        while(!temp.empty() && steps>0){
            steps--;
            history.push(temp.top());
            temp.pop();
        }
        return history.top();
    }
};

// Runtime: 200 ms, faster than 26.32% of C++ online submissions for Design Browser History.
// Memory Usage: 89.1 MB, less than 18.82% of C++ online submissions for Design Browser History.

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */