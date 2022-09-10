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
    void helper(TreeNode* root,int x,int y,map<int,map<int,vector<int>>>& um)
    {
        if(root==nullptr) return;
        um[y][x].push_back(root->val);
        helper(root->left,x+1,y-1,um);
        helper(root->right,x+1,y+1,um);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        map<int,map<int,vector<int>>> um;
        helper(root,0,0,um);
        for(auto i:um)
        {
            vector<int> t;
            for(auto j:i.second)
            {
                auto list=j.second;
                sort(list.begin(),list.end());
                t.insert(t.end(),list.begin(),list.end());
            }
            result.push_back(t);
        }
        return result;
    }
};