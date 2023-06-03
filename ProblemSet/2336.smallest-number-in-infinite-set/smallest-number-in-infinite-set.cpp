class SmallestInfiniteSet {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    set<int> s;
public:
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
            pq.push(i);
    }
    
    int popSmallest() {
        int result=pq.top();
        pq.pop();
        s.insert(result);
        return result;
    }
    
    void addBack(int num) {
        if(!s.count(num))
            return;
        pq.push(num);
        s.erase(num);
    }
};