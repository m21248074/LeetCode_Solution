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
    int maxLevelSum(TreeNode* root) {
        int result=INT_MIN;
        int index=0;
        queue<TreeNode*> q;
        q.push(root);
        int level=1;
        while(!q.empty())
        {
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++)
            {
                auto t=q.front();
                q.pop();
                sum+=t->val;
                if(t->left!=nullptr)
                    q.push(t->left);
                if(t->right!=nullptr)
                    q.push(t->right);
            }
            if(result<sum)
            {
                result=sum;
                index=level;
            }
            level++;
        }
        return index;
    }
};