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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> um;
        int n=inorder.size();
        for(int i=0;i<n;i++)
            um[inorder[i]]=i;
        function<TreeNode*(int,int,int,int)> helper=[&](int is,int ie,int ps,int pe) -> TreeNode*
        {
            if(is>ie||ps>pe) return nullptr;
            TreeNode* root=new TreeNode(postorder[pe]);
            int index=um[postorder[pe]];
            int leftNum=index-is;
            root->left=helper(is,index-1,ps,ps+leftNum-1);
            root->right=helper(index+1,ie,ps+leftNum,pe-1);
            return root;
        };
        return helper(0,n-1,0,n-1);
    }
};