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
    void helper(TreeNode* node,int mn,int mx,int& result)
    {
        // preorder
        if(!node) return;
        result=max(result,abs(node->val-mn));
        result=max(result,abs(mx-node->val));
        mn=min(mn,node->val);
        mx=max(mx,node->val);
        helper(node->left,mn,mx,result);
        helper(node->right,mn,mx,result);
    }
    int maxAncestorDiff(TreeNode* root) {
        int result=0;
        helper(root,root->val,root->val,result);
        return result;
    }
};