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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        vector<TreeNode*> q;
        q.push_back(root);
        int curDepth=1;
        while(!q.empty())
        {
            int n=q.size();
            if(depth-1==curDepth)
            {
                for(auto node:q)
                {
                    if(node->left!=nullptr)
                    {
                        TreeNode* newNode=new TreeNode(val);
                        newNode->left=node->left;
                        node->left=newNode;
                    }
                    else
                        node->left=new TreeNode(val);
                    if(node->right!=nullptr)
                    {
                        TreeNode* newNode=new TreeNode(val);
                        newNode->right=node->right;
                        node->right=newNode;
                    }
                    else
                        node->right=new TreeNode(val);
                }
                break;
            }
            for(int i=0;i<n;i++)
            {
                TreeNode* node=q.front();
                q.erase(q.begin());
                if(node->left!=nullptr)
                    q.push_back(node->left);
                if(node->right!=nullptr)
                    q.push_back(node->right);
            }
            curDepth++;
        }
        return root;
    }
};