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
    string tree2str(TreeNode* t) {
        
        string str = "";
        if(t == nullptr){
            return str;
        }
        convertToStr(t, str);
        return str;
    }
    
private:
    void convertToStr(TreeNode* node, string& str){
        string tempStr;
        if(node == nullptr)
            return;
        
        str += to_string(node->val);
        if(node->left != NULL || node->right != NULL){
            str += "(";
            convertToStr(node->left, str);
            str +=")";
            
            if(node->right){
                str += "(";
                convertToStr(node->right, str);
                str += ")";
            }
        }
    }
};