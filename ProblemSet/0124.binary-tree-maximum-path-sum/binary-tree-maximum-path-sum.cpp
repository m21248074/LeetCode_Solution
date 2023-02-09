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
    int helper(TreeNode* node,int &result)
    {
        if(!node) return 0;
        int left=max(helper(node->left,result),0);
        int right=max(helper(node->right,result),0);
        result=max(result,left+right+node->val);
        return max(left,right)+node->val;
    }
    int maxPathSum(TreeNode* root) {
        int result=INT_MIN;
        helper(root,result);
        return result;
    }
};