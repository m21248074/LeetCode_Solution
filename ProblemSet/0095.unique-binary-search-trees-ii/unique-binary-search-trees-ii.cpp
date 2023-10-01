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
    vector<TreeNode*> generateTrees(int n) {
        function<vector<TreeNode*>(int,int)> helper=[&](int start,int end)->vector<TreeNode*>{
            if(start>end) return {nullptr};
            vector<TreeNode*> result;
            for(int i=start;i<=end;i++)
            {
                auto left=helper(start,i-1);
                auto right=helper(i+1,end);
                for(auto x:left)
                {
                    for(auto y:right)
                    {
                        TreeNode *node=new TreeNode(i);
                        node->left=x;
                        node->right=y;
                        result.push_back(node);
                    }
                }
            }
            return result;
        };
        return helper(1,n);
    }
};