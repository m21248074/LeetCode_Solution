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
    TreeNode* helper(vector<int>& nums,int l,int r)
    {
        if(l>r) return nullptr;
        int mid=(l+r)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        TreeNode *left=helper(nums,l,mid-1);
        TreeNode *right=helper(nums,mid+1,r);
        root->left=left;
        root->right=right;
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};