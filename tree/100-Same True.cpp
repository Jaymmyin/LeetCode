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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //每碰到一个树节点时有两种情况，一是该节点存在；二是该节点不存在。
        if(!p && !q)
        {
            return true;
        }
        //上面排除两个节点 都不存在的情况了
        //如果两个节点只有一个节点是存在的，则肯定不一致，返回false。
        if(!p || !q)
        {
            return false;
        }
        
        //上面排除只有一个节点存在的情况
        //如果两个节点都有值，则比较两个值是否相等，然后继续迭代它的的子左节点和子右节点
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        
    }
};