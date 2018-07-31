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
    TreeNode* invertTree(TreeNode* root) {
        
        queue<TreeNode*> nodeLayer;
        stack<TreeNode*> nodeLayerCopy;
        
        queue<TreeNode*> nodeLayerInvert;
        nodeLayer.push(root);
        nodeLayerInvert.push(root);
        
        TreeNode *topNode = nodeLayerInvert.front();
        while(!nodeLayer.empty())
        {
            vector<int> currList;
            int size = nodeLayer.size();
            
            for(int i=0; i<size; i++)
            {
                TreeNode *node = nodeLayer.front();
                nodeLayer.pop();
                
                if(node != nullptr) //不加这个条件会出现 void return 错误，因为node为null时，没有node->left, node->right
                {
                     currList.push_back(node->val);
                
                    nodeLayer.push(node->left);
                    nodeLayer.push(node->right);
                    //把这一层的节点copy一份到stack中
                    nodeLayerCopy.push(node->left);
                    nodeLayerCopy.push(node->right);
                }
                   
            }
            //将nodeLayerCopy中的节点放到nodeLayerInvert中
            for(int i=0; i<size; i++)
            {
                TreeNode *node = nodeLayerInvert.front();
                nodeLayerInvert.pop();  
                if(node != nullptr)//同上
                {
                    //if(node->left != nullptr)
                    TreeNode *nodeLeft = nodeLayerCopy.top();
                    nodeLayerCopy.pop();
                    //if(nodeLeft != nullptr)
                    node->left = nodeLeft;    //将后入栈、在栈顶的节点依次加入到左右队列里面
                    TreeNode *nodeRight = nodeLayerCopy.top();
                    nodeLayerCopy.pop();
                    //if(node->right != nullptr)
                    node->right  = nodeRight;

                    nodeLayerInvert.push(node->left);
                    nodeLayerInvert.push(node->right);
                }
                
            }
            
            if(currList.size() == 0)
                return topNode;
        }
        
        return root; //不想改了，反正肯定返回是topNode
        
    }
};