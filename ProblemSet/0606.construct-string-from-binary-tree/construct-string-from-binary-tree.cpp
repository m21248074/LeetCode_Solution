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
    void helper(string &s,TreeNode* root)
    {
        if(!root) return;
        s+=to_string(root->val);
        if(!root->left&&!root->right) return;
        s+="(";
        helper(s,root->left);
        s+=")";
        if(root->right)
        {
            s+="(";
            helper(s,root->right);
            s+=")";
        }
    }
    string tree2str(TreeNode* root) {
        string result="";
        helper(result,root);
        return result;
    }
};