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
    int sumOfLeftLeaves(TreeNode* root) {
        
        if(root == nullptr)return 0;
        
        int sum=0;
        vector<int> leftLeaf;
        
        getLeftLeaf(root, leftLeaf);
        cout<<"size of leftLeaf : "<<leftLeaf.size()<<endl;
        for(int i=0; i<leftLeaf.size(); i++){
            sum += leftLeaf[i];
        }
        
        return sum;
    }
    
private:
    void getLeftLeaf(TreeNode* node, vector<int>& leftLeaf){
    
        if(node->left != nullptr){
            if((node->left)->left == nullptr && (node->left)->right == nullptr){
                cout<<"santisfy "<<endl;
                leftLeaf.push_back((node->left)->val);
            }
        }
        
        if(node->left != nullptr)
            getLeftLeaf(node->left, leftLeaf);
        
        if(node->right != nullptr)
            getLeftLeaf(node->right, leftLeaf);
        
    }
    
};