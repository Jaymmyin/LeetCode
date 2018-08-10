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
    int findTilt(TreeNode* root) {
        if(!root)
            return 0;
            
        int sumTilt = 0;
        
        sumTilt = tilt(root);
        
        return sumTilt;
    }
    
private:
    int tilt(TreeNode* node){
        
        if(node == nullptr)
            return 0;
        
        int temp = 0;
        temp = abs(sumSubTree(node->left) - sumSubTree(node->right));
        
        return temp + tilt(node->left) + tilt(node->right);
    }
    
private:
    int sumSubTree(TreeNode* node){
        
        if(node == nullptr)
            return 0;
        
        return node->val + sumSubTree(node->left) + sumSubTree(node->right);
    }
};