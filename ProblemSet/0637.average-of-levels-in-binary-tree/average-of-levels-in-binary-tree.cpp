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
    void helper(vector<pair<double,int>>& records,int order,TreeNode* root)
    {
        if(root==nullptr) return;
        if(records.size()<order)
            records.push_back({0,0});
        records[order-1].first+=root->val;
        records[order-1].second++;
        helper(records,order+1,root->left);
        helper(records,order+1,root->right);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<double,int>> records;
        vector<double> result;
        helper(records,1,root);
        for(auto record:records)
            result.push_back(record.first/double(record.second));
        return result;
    }
};