class MyCircularQueue {
private:
    vector<int> queue;
    int head,tail,cnt,size;
public:
    MyCircularQueue(int k) {
        head=k-1,cnt=0;
        tail=0;
        size=k;
        queue=vector<int>(k);
    }
    bool enQueue(int value) {
        if(isFull()) return false;
        queue[tail]=value;
        tail=(tail+1)%size;
        cnt++;
        return true;
    }
    bool deQueue() {
        if(isEmpty()) return false;
        head=(head+1)%size;
        cnt--;
        return true;
    }
    int Front() {
        return isEmpty()?-1:queue[(head+1)%size];
    }
    int Rear() {
        return isEmpty()?-1:queue[(tail-1+size)%size];
    }
    bool isEmpty() {
        return !cnt;
    }
    bool isFull() {
        return cnt==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */