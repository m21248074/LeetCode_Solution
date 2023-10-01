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
    void traverse(TreeNode* root,int cur,int &result)
    {
        if(root==nullptr) return;
        if(root->left==nullptr&&root->right==nullptr) // root is a leaf
            result=min(result,cur);
        traverse(root->left,cur+1,result);
        traverse(root->right,cur+1,result);
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int result=INT_MAX;
        traverse(root,1,result);
        return result;
    }
};