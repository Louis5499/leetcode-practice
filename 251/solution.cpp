class Node {
    public:
        int val;
        Node *next;
        Node(int value) {
            val = value;
            next = NULL;
        }
};

class Vector2D {
public:
    Node *node = new Node(-1), *head = node;
    Vector2D(vector<vector<int>>& vec) {
        for (auto perVec: vec) {
            for (auto element: perVec) {
                Node *newNode = new Node(element);
                node->next = newNode;
                node = newNode;
            }
        }
    }
    
    int next() {
        head = head->next;
        return head->val;
    }
    
    bool hasNext() {
        return head->next != NULL;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */