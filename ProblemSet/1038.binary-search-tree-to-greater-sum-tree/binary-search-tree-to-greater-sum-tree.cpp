/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int cur = 0;
        helper(root, cur);
        return root;
    }
    void helper(TreeNode*& node, int& cur) {
        if (!node) return;
        helper(node->right, cur);
        node->val += cur;
        cur = node->val;
        helper(node->left, cur);
    }
};