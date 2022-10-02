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
    int calculate(vector<int> &path)
    {
        int result=0;
        int pow=1;
        for(int i=0;i<path.size();i++,pow*=2)
        {
            if(path[path.size()-i-1])
                result+=pow;
        }
        return result;
    }
    void helper(TreeNode* root,vector<int> &path,int &result)
    {
        if(root==nullptr) return;
        else if(root->left==nullptr&&root->right==nullptr) // root is a leaf
        {
            path.push_back(root->val);
            result+=calculate(path);
            path.pop_back();
        }
        path.push_back(root->val);
        helper(root->left,path,result);
        helper(root->right,path,result);
        path.pop_back();
    }
    int sumRootToLeaf(TreeNode* root) {
        int result=0;
        vector<int> path;
        helper(root,path,result);
        return result;
    }
};