class BrowserHistory {
public:
    vector<string> history;
    int i=0;
    BrowserHistory(string homepage) {
        history.emplace_back(homepage);
    }
    
    void visit(string url) {
        history.insert(history.begin()+i+1, url);
        history.erase(history.begin()+i+2, history.end());
        i = history.size()-1;
    }
    
    string back(int steps) {
        i = max(0, i-steps);
        return history[i];
    }
    
    string forward(int steps) {
        i = min((int)history.size()-1, i+steps);
        return history[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */