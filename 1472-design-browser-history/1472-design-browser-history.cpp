class BrowserHistory {
    list<string> bro;
    list<string> :: iterator it;
public:
    BrowserHistory(string homepage) {
        bro.push_back(homepage);
        it = bro.begin();
    }
    
    void visit(string url) {
        auto del = it;
        del++;
        bro.erase(del,bro.end());
        bro.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while(it != bro.begin() and steps-- > 0)
        {
            it--;
        }
        
        return *it;
    }
    
    string forward(int steps) {
        while(it != --bro.end() and steps-- > 0)
        {
            it++;
        }
        
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */