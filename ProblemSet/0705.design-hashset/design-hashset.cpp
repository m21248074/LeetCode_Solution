class MyHashSet {
private:
    vector<bool> data;
public:
    MyHashSet() {
        data.resize(1e6+1,false);
    }
    
    void add(int key) {
        data[key]=true;
    }
    
    void remove(int key) {
        data[key]=false;
    }
    
    bool contains(int key) {
        return data[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */