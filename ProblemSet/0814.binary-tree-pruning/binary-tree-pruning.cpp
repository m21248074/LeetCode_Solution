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
    bool helper(TreeNode* root)
    {
        if(root==nullptr) return false;
        bool left=helper(root->left);
        bool right=helper(root->right);
        if(!left)
            root->left=nullptr;
        if(!right)
            root->right=nullptr;
        if(left||right||root->val==1)
            return true;
        return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(helper(root))
            return root;
        return nullptr;
    }
};
