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
    void traverse(vector<vector<int>> &result,TreeNode *root,vector<int> &path,int targetSum)
    {
        if(root==nullptr) return;
        else if(root->left==nullptr&&root->right==nullptr) // root is a leaf
        {
            if(!(targetSum-root->val))
            {
                path.push_back(root->val);
                result.push_back(path);
                path.pop_back();
            }
            return;
        }
        path.push_back(root->val);
        traverse(result,root->left,path,targetSum-root->val);
        traverse(result,root->right,path,targetSum-root->val);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        traverse(result,root,path,targetSum);
        return result;
    }
};