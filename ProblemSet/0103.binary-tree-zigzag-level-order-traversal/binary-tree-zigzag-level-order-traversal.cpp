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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if(!root)
            return result;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> levels;
            for(int i=0;i<size;i++)
            {
                TreeNode *temp=q.front();
                levels.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                q.pop();
            }
            if(result.size()%2)
                reverse(levels.begin(),levels.end());
            result.push_back(levels);
        }
        return result;
    }
};