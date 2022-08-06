class MyCalendar {
private:
    vector<pair<int,int>> data;
public:
    MyCalendar() {
    }
    bool book(int start, int end) {
        for(auto cal:data)
        {
            if(start<=cal.first&&cal.first<end) return false;
            if(start>=cal.first&&start<cal.second) return false;
        }
        data.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */