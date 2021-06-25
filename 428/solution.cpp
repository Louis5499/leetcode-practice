/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        return encode(root);
    }
	
    string encode(Node *node) {
        string cur = "";
        if (node == NULL) return cur;
        cur += to_string(node->val) + " ";
        cur += to_string(node->children.size()) + " ";
        for (Node* child: node->children) cur += encode(child) + " ";
        return cur;
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }
    
    Node* decode(stringstream& ss) {
        ss.peek();
        if (ss.eof()) return NULL;
        Node* node = new Node();
        int childSize = 0;
        ss >> node->val >> childSize;
        while (childSize--) node->children.emplace_back(decode(ss));
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));