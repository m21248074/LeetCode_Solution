/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        unordered_map<TreeNode*,vector<TreeNode*>> um;
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        function<void(TreeNode*,TreeNode*)> helper=[&](TreeNode *node,TreeNode *pre){
            if(node==nullptr) return;
            if(um.count(node)) return;
            if(pre!=nullptr)
            {
                um[node].push_back(pre);
                um[pre].push_back(node);
            }
            helper(node->left,node);
            helper(node->right,node);
        };
        helper(root,nullptr);
        while(!q.empty())
        {
            if(k==0)
            {
                for(int i=q.size();i>0;i--)
                {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            for(int i=q.size();i>0;i--)
            {
                TreeNode *t=q.front();
                q.pop();
                for(TreeNode *node:um[t])
                {
                    if(visited.count(node)) continue;
                    visited.insert(node);
                    q.push(node);
                }
            }
            k--;
        }
        return result;
    }
};