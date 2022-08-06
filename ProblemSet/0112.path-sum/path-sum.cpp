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
    bool hasPathSum(TreeNode* root, int targetSum,int curSum) {
        if(root==nullptr) return false;
        else if(curSum+root->val==targetSum&&root->left==nullptr&&root->right==nullptr) return true;
        return hasPathSum(root->left,targetSum,curSum+root->val)||hasPathSum(root->right,targetSum,curSum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPathSum(root,targetSum,0);
    }
};