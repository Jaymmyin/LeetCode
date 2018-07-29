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
    int minDepth(TreeNode* root) {
        
        int min=0;
        queue<TreeNode*> que;
        que.push(root);
        int count = 0;
        int mark = 1; //mark为1表示该节点有叶子节点，可以用来更新每一层中的每一个节点
        int layer=0, markLayer=0;
        
        while(!que.empty()){
            
            layer++;
            vector<int> currList;
            int size = que.size();
            
            for(int i=0; i<size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                if(node == nullptr)
                {
                    if(mark == 0 && markLayer != layer) //叶子节点的层mark=0 是不能考虑进来的
                        return min;
                }else{
                    if(mark != 0)//如果mark为0，表示已经碰到过叶子节点了，mark也不会变为1
                    {
                        if((node->left == nullptr) && (node->right == nullptr))
                        {
                            mark = 0;
                            markLayer = layer; //记住哪一层是第一次出现叶子节点的层
                            //min++;
                        }
                    }
                    currList.push_back(node->val);
                    que.push(node->left);
                    que.push(node->right);
                }
            }
            count = currList.size();//每一层非空节点的个数
            if(!currList.empty())
                min++;
        }
        
        return min;
    }
};