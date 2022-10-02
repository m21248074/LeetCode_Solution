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
    bool helper(TreeNode* root,int same)
    {
        if(root==nullptr) return true;
        else if(root->val!=same) return false;
        return helper(root->left,same)&&helper(root->right,same);
    }
    bool isUnivalTree(TreeNode* root) {
        int same=root->val;
        return helper(root,same);
    }
};