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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> g;
        function<void(TreeNode*)> travel=[&](TreeNode* r){ //preorder
            if(!r) return;
            if(r->left)
            {
                g[r->val].push_back(r->left->val);
                g[r->left->val].push_back(r->val);
            }
            if(r->right)
            {
                g[r->val].push_back(r->right->val);
                g[r->right->val].push_back(r->val);
            }
            travel(r->left);
            travel(r->right);
        };
        travel(root);
        unordered_set<int> visited;
        queue<int> q;
        q.push(start);
        int result=-1;
        while(!q.empty())
        {
            result++;
            for(int i=q.size();i>0;i--)
            {
                int node=q.front();
                q.pop();
                visited.insert(node);
                for(int nei:g[node])
                {
                    if(!visited.count(nei))
                        q.push(nei);
                }
            }
        }
        return result;
    }
};