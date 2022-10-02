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

class Solution {
public:
    void traverse(Node *root,int &result,int order)
    {
        if(root==nullptr) return;
        result=max(result,order);
        for(auto child:root->children)
            traverse(child,result,order+1);
    }
    int maxDepth(Node* root) {
        int result=0;
        traverse(root,result,1);
        return result;
    }
};