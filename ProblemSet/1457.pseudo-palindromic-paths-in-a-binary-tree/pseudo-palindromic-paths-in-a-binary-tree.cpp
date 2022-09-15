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
    void traverse(TreeNode* root,int path,int &cnt)
    {
        if(root==nullptr) return;
        path^=1<<root->val;
        if(root->left==nullptr && root->right==nullptr) // leaf node
        {
            if(__builtin_popcount(path)<=1)
                cnt++;
        }
        traverse(root->left,path,cnt);
        traverse(root->right,path,cnt);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int cnt=0;
        traverse(root,0,cnt);
        return cnt;
    }
};