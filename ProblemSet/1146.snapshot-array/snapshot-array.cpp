class SnapshotArray {
private:
    int snapID;
    map<int,map<int,int>> m;
public:
    SnapshotArray(int length) {
        snapID=0;
        for(int i=0;i<length;i++)
            m[i]={{0,0}};
    }
    
    void set(int index, int val) {
        m[index][snapID]=val;
    }
    
    int snap() {
        return snapID++;
    }
    
    int get(int index, int snap_id) {
        auto iter=m[index].upper_bound(snap_id);
        iter--;
        return iter->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */