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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        queue<TreeNode*> que;
        que.push(s);
        bool result;
        while(!que.empty()){
            int size = que.size();
            
            for(int i=0; i<size; i++){
                TreeNode *node = que.front();
                que.pop();
                
                if(node->val == t->val){
                    result = subTree(node, t);
                    if(result)
                        return true;
                }
                if(node->left)
                    que.push(node->left);
                
                if(node->right)
                    que.push(node->right);
            }
        }
        if(!result)
            return false;
    }
    
private:
    bool subTree(TreeNode* node, TreeNode* t){
        
        if((node == nullptr && t != nullptr) || (node != nullptr && t == nullptr)){
            return false;
        }else if(node == nullptr && t == nullptr){
            return true;
        }
        
        if(node->val != t->val){
            return false;
        }else{
            return subTree(node->left, t->left) && subTree(node->right, t->right);
        }
    }
};