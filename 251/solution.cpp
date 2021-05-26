class Vector2D {
public:
    vector<vector<int>>::iterator beg, end;
    int j=0;
    Vector2D(vector<vector<int>>& vec) {
        beg = vec.begin();
        end = vec.end();
    }
    
    int next() {
        hasNext();
        return (*beg)[j++];
    }
    
    bool hasNext() {
        while (beg != end && j == (*beg).size()) {
            beg++;
            j=0;
        }
        return beg != end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */