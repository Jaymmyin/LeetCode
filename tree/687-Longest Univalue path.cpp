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
    int longestUnivaluePath(TreeNode* root) {
        if(!root)return 0;
        
        int res = 0;
        
        if(root->left != NULL && (root->left)->val == root->val){
            res = 1 + dfs(root->left);
        }
        
        if(root->right != NULL && (root->right)->val == root->val){
            res += 1 + dfs(root->right);
        }
        
        return max(res, max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)));
    }

private:
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int res = 0;
        if(root->left && (root->left)->val == root->val){
            res = 1 + dfs(root->left);
        }
        
        if(root->right && (root->right)->val == root->val){
            res = max(res, 1 + dfs(root->right));
        }
        
        return res;
    }
};