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
class BSTIterator {
private:
    int index;
    vector<int> result;
public:
    void helper(TreeNode* root)
    {
        if(!root) return;
        helper(root->left);
        result.push_back(root->val);
        helper(root->right);
    }
    BSTIterator(TreeNode* root) {
        index=0;
        helper(root);
    }
    int next() {
        return result[index++];
    }
    bool hasNext() {
        if(result.size()>index)
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */