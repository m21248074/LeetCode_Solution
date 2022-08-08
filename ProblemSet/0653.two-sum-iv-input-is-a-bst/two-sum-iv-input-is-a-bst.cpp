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
private:
    unordered_map<int,int> m;
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr) return false;
        bool left=findTarget(root->left,k);
        bool right=findTarget(root->right,k);
        if(left||right) return true;
        else if(m[k-root->val]) return true;
        m[root->val]=1;
        return false;
    }
};