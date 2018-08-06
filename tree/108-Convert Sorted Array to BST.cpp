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
声明一个节点 
TreeNode *root;
*/

/*
初始化一个节点 
root = new TreeNode(0)
root->val = xxx;
root->left = ...;
root->right = ...;
*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        TreeNode *tree;
        
        tree = getSortedArray(tree, nums, 0, nums.size()-1);
            
        return tree;
    }
    
    TreeNode* getSortedArray(TreeNode* tree, vector<int>& nums, int start, int end){
        if(start > end){
            return NULL;
        }
            
        tree = new TreeNode(0);
        tree->val = nums[(start + end)/2];
        tree->left = getSortedArray(tree, nums, start, (start+end)/2 - 1);
        tree->right = getSortedArray(tree, nums, (start+end)/2+1, end);
        
        return tree;
    }
};