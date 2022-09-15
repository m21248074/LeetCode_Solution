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
    void traverse(vector<int> &result,TreeNode* root,int order)
    {
        if(root==nullptr) return;
        if(result.size()==order)
            result.push_back(root->val);
        result[order]=root->val;
        traverse(result,root->left,order+1);
        traverse(result,root->right,order+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        traverse(result,root,0);
        return result;
    }
};