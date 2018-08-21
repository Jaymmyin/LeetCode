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
    bool findTarget(TreeNode* root, int k) {
        if(!root)return false;
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            int size = que.size();
            
            for(int i=0; i<size; i++){
                bool res = false;
                TreeNode *node = que.front();
                que.pop();
                res = hasSum(node, root, k); 
                if(res)return true;
                
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
                
            }
        }
        return false;
    }
    
private:
    bool hasSum(TreeNode* node, TreeNode* root, int k){
        bool res = false;
        
        if(!root)return res;
        if(root == node)return res;//要除去root中node这个节点
        if(node->val + root->val == k){
            res = true;
        }
        return res || hasSum(node, root->left, k) || hasSum(node, root->right, k);
    }
    
};