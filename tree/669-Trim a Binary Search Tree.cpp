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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        //如果一个节点不满足条件，那么他的左子树或者右子树当中 至少有一个不满足条件
        if(!root) return NULL;
        
        trim(root, L, R);
        return root;
    }
    
private:
    void trim(TreeNode*& root, int L, int R){
        if(!root)
            return;
        
        if(root->val < L){
            root = root->right;
            trim(root, L, R);
        }else if(root->val > R){
            root = root->left;
            trim(root, L, R);
        }else{
            trim(root->left, L, R);
            trim(root->right, L, R);
        }
    }
};