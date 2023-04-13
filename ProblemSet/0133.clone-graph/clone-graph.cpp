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
        unordered_map<Node*,Node*> um;
        function<Node*(Node*)> helper=[&](Node* node)->Node*{
            if(!node) return nullptr;
            if(um.count(node)) return um[node];
            Node* copy=new Node(node->val);
            um[node]=copy;
            for(Node* neighbor:node->neighbors)
                copy->neighbors.push_back(helper(neighbor));
            return copy;
        };
        return helper(node);
    }
};