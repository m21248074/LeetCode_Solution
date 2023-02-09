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
    int helper(TreeNode* node,long& sum,long& result)
    {
        if(!node) return 0;
        int left=helper(node->left,sum,result);
        int right=helper(node->right,sum,result);
        if(sum)
            result=max({result,(sum-left)*left,(sum-right)*right});
        return node->val+left+right;
    }
    int maxProduct(TreeNode* root) {
        int Mod=1e9+7;
        long sum=0;
        long result=0;
        sum=helper(root,sum,result);
        helper(root,sum,result);
        return result%Mod;
    }
};