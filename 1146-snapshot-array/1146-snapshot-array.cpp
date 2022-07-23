class SnapshotArray {
private:
    unordered_map<int,int> mapArr;
    map<int,unordered_map<int,int>> snapTable;
    int snap_id;
public:
    SnapshotArray(int length) {
        snap_id = -1;
    }
    
    void set(int index, int val) {
        mapArr[index] = val;
    }
    
    int snap() {
        snap_id++;
        snapTable[snap_id] = mapArr;
        return snap_id;
    }
    
    int get(int index, int snap_id) {
        return snapTable[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */