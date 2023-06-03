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
    int widthOfBinaryTree(TreeNode* root) {
        int result=0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int left=q.front().second;
            int right=q.back().second;
            result=max(result,right-left+1);
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                auto t=q.front();
                q.pop();
                int index=t.second-left;
                TreeNode* cur=t.first;
                if(cur->left)
                    q.push({cur->left,(long long)index*2+1});
                if(cur->right)
                    q.push({cur->right,(long long)index*2+2});
            }
        }
        return result;
    }
};