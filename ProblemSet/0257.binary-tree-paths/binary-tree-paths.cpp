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
    void traverse(TreeNode* root,vector<string> &result,vector<int> &path)
    {
        if(root==nullptr) return;
        else if(root->left==nullptr&&root->right==nullptr) // root is a leaf
        {
            path.push_back(root->val);
            string t=to_string(path[0]);
            for(int i=1;i<path.size();i++)
                t+="->"+to_string(path[i]);
            result.push_back(t);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        traverse(root->left,result,path);
        traverse(root->right,result,path);
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        traverse(root,result,path);
        return result;
    }
};