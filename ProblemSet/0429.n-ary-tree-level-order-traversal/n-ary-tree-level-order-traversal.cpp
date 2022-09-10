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
    void helper(int index,Node* root, vector<vector<int>> &result)
    {
        if(root==nullptr) return;
        while(result.size()<=index)
            result.push_back(vector<int>());
        result[index].push_back(root->val);
        for(auto child:root->children)
            helper(index+1,child,result);
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        helper(0,root,result);
        return result;
    }
};