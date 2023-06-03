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
    int longestZigZag(TreeNode* root) {
        int result=0;
        function<pair<int,int>(TreeNode*)> helper=[&](TreeNode *cur)->pair<int,int>{
            if(cur==nullptr) return make_pair(0,0);
            auto p1=helper(cur->left);
            auto p2=helper(cur->right);
            result=max(result,max(p1.second,p2.first));
            return make_pair(p1.second+1,p2.first+1);
        };
        helper(root);
        return result;
    }
};