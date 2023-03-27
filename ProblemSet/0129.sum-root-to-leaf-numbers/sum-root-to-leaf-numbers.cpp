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
    int sumNumbers(TreeNode* root) {
        int result=0;
        function<void(int,TreeNode*)> helper=[&](int value,TreeNode *cur){
            value=value*10+cur->val;
            if(cur->left==nullptr&&cur->right==nullptr) // cur is leaf node
            {
                result+=value;
                return;
            }
            if(cur->left)
                helper(value,cur->left);
            if(cur->right)
                helper(value,cur->right);
        };
        helper(0,root);
        return result;
    }
};