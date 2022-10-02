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
    void traverse(TreeNode* root,set<int> &s)
    {
        if(root==nullptr) return;
        traverse(root->left,s);
        s.insert(root->val);
        traverse(root->right,s);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        traverse(root,s);
        if(s.size()==1) return -1;
        auto it=s.begin();
        it++;
        return *it;
    }
};