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
    int findSecondMinimumValue(TreeNode* root) {
        //先找到最小值，再找大于最小值的最小值，如果没有则为-1
        if(!root)return -1;
        
        int minValue = root->val;
        int subMin = INT_MAX;
        
        findMin(root, minValue);
        
        findSub(root, subMin, minValue);
        
        if(subMin == INT_MAX){
            return -1;
        }else{
            return subMin;
        }
    }
    
    void findMin(TreeNode* root, int& minValue){
        if(!root)return;
        
        minValue = min(minValue, root->val);
        findMin(root->left, minValue);
        findMin(root->right, minValue);
    }
    
    void findSub(TreeNode* root, int& subMin, int minValue){
        if(!root)return;
        
        if(root->val<subMin && root->val>minValue){
            subMin = root->val;
        }
        findSub(root->left, subMin, minValue);
        findSub(root->right, subMin, minValue);
    }
};