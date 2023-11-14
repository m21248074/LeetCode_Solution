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
    int averageOfSubtree(TreeNode* root) {
        int result=0;
        function<pair<int,int>(TreeNode*)> dfs=[&](TreeNode* node)->pair<int,int>{
            if(!node) return {0,0};
            pair<int,int> left=dfs(node->left);
            pair<int,int> right=dfs(node->right);
            left.first+=right.first+node->val;
            left.second+=right.second+1;
            if(left.first/left.second==node->val)
                result++;
            return left;
        };
        dfs(root);
        return result;
    }
};