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
private:   
    TreeNode *cur;
public:
    void traverse(TreeNode* root)
    {
        if(root==nullptr) return;
        traverse(root->left);
        cur->right=new TreeNode(root->val);
        cur=cur->right;
        traverse(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *dummy=new TreeNode();
        cur=dummy;
        traverse(root);
        return dummy->right;
    }
};