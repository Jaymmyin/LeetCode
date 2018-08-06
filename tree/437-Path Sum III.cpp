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
    int pathSum(TreeNode* root, int sum) {
        
        if(root == nullptr)return 0;
        int stats=0;
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            int size = que.size();
            
            for(int i=0; i<size; i++){
                TreeNode *node = que.front();
                que.pop();
                int pathSum = 0;
                stats += hasNumOfPath(node, sum, pathSum);
                if(node->left)
                    que.push(node->left);
                
                if(node->right)
                    que.push(node->right);
            }
        }
        
        return stats;
    }
    
private:
    int hasNumOfPath(TreeNode* node, int sum, int pathSum){
        int temp = 0;
        if(node == nullptr)
            return 0;
        if(pathSum + node->val == sum){
            temp++;
        }
        
        return temp + hasNumOfPath(node->left, sum, pathSum+node->val) + hasNumOfPath(node->right, sum, pathSum+node->val);
    }
        
};