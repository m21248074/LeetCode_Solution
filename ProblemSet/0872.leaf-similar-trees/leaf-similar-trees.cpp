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
    void traverse(TreeNode* root,vector<int> &result)
    {
        if(root==nullptr) return;
        else if(root->left==nullptr&&root->right==nullptr) // root is a leaf
            result.push_back(root->val);
        traverse(root->left,result);
        traverse(root->right,result);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> result1;
        vector<int> result2;
        traverse(root1,result1);
        traverse(root2,result2);
        if(result1.size()!=result2.size()) return false;
        for(int i=0;i<result1.size();i++)
            if(result1[i]!=result2[i]) return false;
        return true;
    }
};