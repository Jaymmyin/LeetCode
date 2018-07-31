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
    bool hasPathSum(TreeNode* root, int sum) {
        //树的问题好难，写了半天最后还是参考别人写的，最后发现别人很简单就实现了。。
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr) return sum-root->val == 0;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
        
    }
};