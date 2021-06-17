class RangeModule {
public:
    map<int, int> inter;
    RangeModule() {}
    
    void addRange(int left, int right) {
        auto l = inter.upper_bound(left), r = inter.upper_bound(right);
        if (l != inter.begin()) {
            l--;
            if (l->second < left) l++;
        }
        if (l != r) {
            left = min(left, l->first);
            right = max(right, (--r)->second);
            inter.erase(l, ++r);
        }
        inter[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = inter.upper_bound(left);
        if (it == inter.begin() || (--it)->second < right) return false;
        return true;
    }
    
    void removeRange(int left, int right) {
        auto l = inter.upper_bound(left), r = inter.upper_bound(right); 
        if (l != inter.begin()) {
            l--;
            if (l->second < left) l++;
        }
        if (l == r) return;
        int l1 = min(left, l->first), r1 = max(right, (--r)->second);
        inter.erase(l, ++r);
        if (l1 < left) inter[l1] = left;
        if (r1 > right) inter[right] = r1;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */