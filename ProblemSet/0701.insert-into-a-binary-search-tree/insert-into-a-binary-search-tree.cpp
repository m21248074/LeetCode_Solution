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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr)
        {
            root=new TreeNode(val);
            return root;
        }
        TreeNode *a=root,*b;
        while(a!=nullptr)
        {
            b=a;
            if(a->val>val)
                a=a->left;
            else // a->val<val
                a=a->right;
        }
        if(b->val>val)
            b->left=new TreeNode(val);
        else
            b->right=new TreeNode(val);
        return root;
    }
};