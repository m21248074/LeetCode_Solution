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
    int distributeCoins(TreeNode* root) {
        int result=0;
        function<int(TreeNode*)> dfs=[&](TreeNode* node)->int{
            if (node == NULL)
                return 0;
            int left = dfs(node->left);
            int right = dfs(node->right);
            result += abs(left) + abs(right);
            return node->val - 1 + left + right;
        };
        dfs(root);
        return result;
    }
};