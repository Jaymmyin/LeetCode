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
    bool isBalanced(TreeNode* root) {
        
        if(root == nullptr)
            return true;
        //左边是树是平衡树 & 右边的树是平衡树 & 左边树平衡因子-右边的平衡因子 绝对值不大于1
        return isBalanced(root->left) && isBalanced(root->right) && (abs(getBF(root->left) - getBF(root->right)) < 2);
    }
    
private:
    int getBF(TreeNode* node){
        if(node == nullptr)
            return 0;

        return 1 + max(getBF(node->left), getBF(node->right));
    }
};