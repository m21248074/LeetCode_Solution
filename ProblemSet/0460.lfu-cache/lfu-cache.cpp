class LFUCache {
private:
    int capacity;
    int minFreq;
    unordered_map<int,pair<int,int>> um;
    unordered_map<int,list<int>> freq;
    unordered_map<int,list<int>::iterator> iter;
public:
    LFUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(!um.count(key)) return -1;
        freq[um[key].second].erase(iter[key]);
        um[key].second++;
        freq[um[key].second].push_back(key);
        iter[key]=--freq[um[key].second].end();
        if(!freq[minFreq].size())
            minFreq++;
        return um[key].first;
    }
    
    void put(int key, int value) {
        if(!capacity)
            return;
        if(get(key)!=-1)
        {
            um[key].first=value;
            return;
        }
        if(um.size()>=capacity)
        {
            um.erase(freq[minFreq].front());
            iter.erase(freq[minFreq].front());
            freq[minFreq].pop_front();
        }
        um[key]=pair<int,int>(value,1);
        freq[1].push_back(key);
        iter[key]=--freq[1].end();
        minFreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */