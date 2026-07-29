class BrowserHistory {
public:
    stack<string> prev, next;
    BrowserHistory(string homepage) { prev.push(homepage); }

    void visit(string url) {
        while (!next.empty())
            next.pop();
        prev.push(url);
    }

    string back(int steps) {
        while (prev.size() > 1 && steps--) {
            next.push(prev.top());
            prev.pop();
        }
        return prev.top();
    }

    string forward(int steps) {
        while (steps-- && !next.empty()) {
            prev.push(next.top());
            next.pop();
        }
        return prev.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */