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
�����������кõ����ʣ�
    1��������ڵ�����������գ��������������нڵ��ֵ��С�����ĸ��ڵ��ֵ��
    2��������ڵ�����������գ��������������нڵ��ֵ���������ĸ��ڵ��ֵ��
    3������ڵ����������Ҳ�ֱ�Ϊ�����������
    4��û�м�ֵ��ȵĽڵ�
    
    ע����converBst���β���&��ʹ�á�
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