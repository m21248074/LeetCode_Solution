class MyCalendarThree {
private:
    map<int,int> m;
public:
    MyCalendarThree() {}
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int result=0;
        int cnt=0;
        for(auto i:m)
        {
            cnt+=i.second;
            result=max(result,cnt);
        }
        return result;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */