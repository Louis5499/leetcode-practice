class SnapshotArray {
public:
    unordered_map<int, unordered_map<int, int>> snapArr;
    int curIdx = 0;
    SnapshotArray(int length) {}
    
    void set(int index, int val) {
        snapArr[curIdx][index] = val;
    }
    
    int snap() {
        return curIdx++;
    }
    
    int get(int index, int snap_id) {
        while (snap_id > 0 && snapArr[snap_id].find(index) == snapArr[snap_id].end()) snap_id--;
        return snapArr[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */