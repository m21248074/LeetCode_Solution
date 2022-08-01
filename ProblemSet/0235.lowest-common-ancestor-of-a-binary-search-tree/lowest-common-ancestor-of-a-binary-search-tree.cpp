/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* find(TreeNode* root,int min,int max)
    {
        if(root==nullptr) return nullptr;
        if(root->val<min)
            return find(root->right,min,max);
        else if(root->val>max)
            return find(root->left,min,max);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int min_value=min(p->val,q->val);
        int max_value=max(p->val,q->val);
        return find(root,min_value,max_value);
    }
};