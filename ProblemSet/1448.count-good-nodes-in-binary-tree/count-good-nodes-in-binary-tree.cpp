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
    void helper(int &result,TreeNode* root,int max)
    {
        if(root==nullptr) return;
        if(root->val>=max)
        {
            result++;
            max=root->val;
        }
        helper(result,root->left,max);
        helper(result,root->right,max);
    }
    int goodNodes(TreeNode* root) {
        int result=0;
        helper(result,root,root->val);
        return result;
    }
};