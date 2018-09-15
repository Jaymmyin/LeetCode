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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return NULL;
        
        if(root->val == val){
            return root;
        }else if(root->val > val){//利用BST的性质，这里分开讨论、判断
            return searchBST(root->left, val);
        }else{
            return searchBST(root->right, val);
        }
    
    }
    
};