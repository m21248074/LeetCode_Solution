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
    void traverse(TreeNode* root,int &result,int &pre)
    {
        if(root==nullptr) return;
        traverse(root->left,result,pre);
        if(pre!=INT_MIN)
            result=min(result,abs(pre-root->val));
        pre=root->val;
        traverse(root->right,result,pre);
    }
    int minDiffInBST(TreeNode* root) {
        int pre=INT_MIN;
        int result=INT_MAX;
        traverse(root,result,pre);
        return result;
    }
};