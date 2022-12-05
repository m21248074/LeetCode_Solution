class MedianFinder {
private:
    priority_queue<int> small,large;
public:
    MedianFinder() {}
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(small.size()<large.size())
        {
            small.push(-large.top());
            large.pop();
        }
    }
    double findMedian() {
        return small.size()>large.size()?small.top():0.5*(small.top()-large.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */