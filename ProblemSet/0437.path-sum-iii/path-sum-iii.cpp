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
    void helper(TreeNode* root,int target,long sum,vector<TreeNode*> &path,int &result)
    {
        if(root==nullptr) return;
        sum+=root->val;
        path.push_back(root);
        if(sum==target) result++;
        long t=sum;
        for(int i=0;i<path.size()-1;i++)
        {
            t-=path[i]->val;
            if(t==target) result++;
        }
        helper(root->left,target,sum,path,result);
        helper(root->right,target,sum,path,result);
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        int result=0;
        vector<TreeNode*> path;
        helper(root,targetSum,0,path,result);
        return result;
    }
};