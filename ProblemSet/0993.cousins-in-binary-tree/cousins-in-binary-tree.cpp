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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        bool isX=false,isY=false;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* cur=q.front();
                q.pop();
                if(cur->val==x) isX=true;
                else if(cur->val==y) isY=true;
                if(cur->left!=nullptr&&cur->right!=nullptr)
                {
                    int left=cur->left->val;
                    int right=cur->right->val;
                    if((left==x&&right==y)||(left==y&&right==x)) return false;
                }
                if(cur->left!=nullptr)
                    q.push(cur->left);
                if(cur->right!=nullptr)
                    q.push(cur->right);
            }
            if(isX&&isY) return true;
            else if(isX||isY) return false;
        }
        return false;
    }
};