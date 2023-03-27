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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        unordered_map<string,int> um;
        function<string(TreeNode*)> helper=[&](TreeNode* node)->string{
            if(!node) return "#";
            string str=to_string(node->val)+","+helper(node->left)+","+helper(node->right);
            if(um[str]==1)
                result.push_back(node);
            um[str]++;
            return str;
        };
        helper(root);
        return result;
    }
};