class RandomizedSet {
private:
    vector<int> data;
    unordered_map<int,int> um;
public:
    RandomizedSet() {}
    bool insert(int val) {
        if(um.count(val)) return false;
        data.push_back(val);
        um[val]=data.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!um.count(val)) return false;
        int last=data.back();
        um[last]=um[val];
        data[um[val]]=last;
        data.pop_back();
        um.erase(val);
        return true;
    }
    
    int getRandom() {
        return data[rand()%data.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */