/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
二叉搜索树有好的性质：
    1、若任意节点的左子树不空，则左子树上所有节点的值均小于它的根节点的值；
    2、若任意节点的右子树不空，则右子树上所有节点的值均大于它的根节点的值；
    3、任意节点的左、右子树也分别为二叉查找树；
    4、没有键值相等的节点
    
    注意在converBst的形参中&的使用。
*/
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        
        int sum = 0;
        
        convertBst(root, sum);
        
        return root;
    }
    
private:
    void convertBst(TreeNode*& node, int& sum){
        
        if(node == nullptr)
            return;
        
        if(node != nullptr){
            convertBst(node->right, sum);
            node->val += sum;
            sum = node->val;
            convertBst(node->left, sum);    
            
        }
        
        
    }
};