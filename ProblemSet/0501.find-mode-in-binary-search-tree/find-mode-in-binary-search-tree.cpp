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
    void traverse(TreeNode* root,unordered_map<int,int> &um,int &max_cnt)
    {
        if(root==nullptr) return;
        traverse(root->left,um,max_cnt);
        um[root->val]++;
        max_cnt=max(max_cnt,um[root->val]);
        traverse(root->right,um,max_cnt);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        unordered_map<int,int> um;
        int max_cnt=INT_MIN;
        traverse(root,um,max_cnt);
        for(auto i:um)
        {
            if(i.second==max_cnt)
                result.push_back(i.first);
        }
        return result;
    }
};