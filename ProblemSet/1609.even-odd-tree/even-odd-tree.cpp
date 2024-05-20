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
    bool isEvenOddTree(TreeNode* root) {
        bool isOdd=true;
        queue<TreeNode*> q;
        q.push(root);
        int temp=0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                if(isOdd)
                {
                    if(t->val%2==0||t->val<=temp)
                        return false;
                }
                else // is even
                {
                    if(t->val%2||t->val>=temp&&temp!=0)
                        return false;
                }
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
                temp=t->val;
            }
            isOdd=!isOdd;
            temp=0;
        }

        return true;
    }
};