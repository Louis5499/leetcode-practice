/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;           
        }

        if (memo.find(node) == memo.end()) {
            memo[node] = new Node(node->val, {});
            for (auto subNodes: node->neighbors) {
                memo[node]->neighbors.push_back(cloneGraph(subNodes));
            }
        }
        return memo[node];
    }
private:
    unordered_map<Node*, Node*> memo;
};