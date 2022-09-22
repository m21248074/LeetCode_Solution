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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int order=0;
        vector<TreeNode*> q;
        q.push_back(root);
        while(!q.empty())
        {
            int n=q.size();
            if(order%2)
            {
                int l=0;
                int r=n-1;
                while(l<r)
                {
                    int t=q[l]->val;
                    q[l]->val=q[r]->val;
                    q[r]->val=t;
                    l++;
                    r--;
                }
            }
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.erase(q.begin());
                if(node->left)
                    q.push_back(node->left);
                if(node->right)
                    q.push_back(node->right);
            }
            order++;
        }
        return root;
    }
};