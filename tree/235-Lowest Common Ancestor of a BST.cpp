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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        //如果节点在root的两侧，root就是最低父节点；如果在同侧，则将左节点或者右节点当做根节点再迭代
        
        int left=0, right=0; //设立标志位，指示p, q的位置。
        if(root == nullptr)
            return nullptr;
        
        if((root->val) == p->val || (root->val) == q->val)
            return root;
        
        if(root->left != nullptr)
            left = judgeLeftRight(root->left, p, q);
        
        if(root->right != nullptr)
            right = judgeLeftRight(root->right, p, q);
        
        cout<<"left is : "<<left<<endl;
        cout<<"right is : "<<right<<endl;
        
        if(left == 1 && right == 1){
            cout<<"return the value : "<<root->val<<endl;
            return root;
        }else if(right == 2){
            if(((root->right)->val == p->val) || ((root->right)->val == q->val))
                return root->right;
            return lowestCommonAncestor(root->right, p, q);
        }else{
            if(((root->left)->val == p->val) || ((root->left)->val == q->val))
                return root->left;
            return lowestCommonAncestor(root->left, p, q);
        }
    }
    
private:
    int judgeLeftRight(TreeNode* node, TreeNode* p, TreeNode* q){
        
        int temp=0;
        if(!node)
            return 0;
        
        if(node){
            if((node->val == p->val) || (node->val == q->val))
            {
                temp++;
            }

            return temp + judgeLeftRight(node->left, p, q) + judgeLeftRight(node->right, p, q);
        }    
    }
    
};