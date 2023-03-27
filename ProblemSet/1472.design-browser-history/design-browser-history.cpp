class BrowserHistory {
private:
    list<string> history;
    list<string>::iterator cur;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur=history.begin();
    }
    
    void visit(string url) {
        cur++;
        if(cur==history.end())
        {
            history.push_back(url);
            cur=history.end();
            cur--;
        }
        else
        {
            cur=history.insert(cur,url);
            auto temp=cur;
            temp++;
            history.erase(temp,history.end());
        }
    }
    
    string back(int steps) {
        if(cur==history.begin())
            return *cur;
        for(int i=0;i<steps;i++)
        {
            cur--;
            if(cur==history.begin())
                break;
        }
        return *cur;
    }
    
    string forward(int steps) {
        //bool can=true;
        //auto temp=cur;
        for(int i=0;i<steps;i++)
        {
            cur++;
            if(cur==history.end())
            {
                cur--;
                break;
            }
        }
        //cout << int(can) << endl;
        //if(can)
        //    cur=temp;
        return *cur;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */