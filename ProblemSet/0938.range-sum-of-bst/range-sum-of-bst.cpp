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
    int result;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root!=nullptr)
        {
            if(low<=root->val&&root->val<=high)
                result+=root->val;
            rangeSumBST(root->left,low,high);
            rangeSumBST(root->right,low,high);
        }
        return result;
    }
};