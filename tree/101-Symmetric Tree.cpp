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
    bool isSymmetric(TreeNode* root) {
        
        queue<TreeNode*> que1;
        queue<TreeNode*> que2;
        que1.push(root);
        que2.push(root);
        
        stack<TreeNode*> stk;
        //stk.push(root);
        
        while(!que1.empty())
        {
            int size = que1.size();
            for(int i=0; i<size; i++)
            {
                TreeNode *node = que2.front(); //que2就是为了copy一份que1，然后存到栈stk的一部分
                que2.pop();
                stk.push(node);
            }
            
            for(int i=0; i<size; i++)
            {
                TreeNode *node1 = que1.front();
                //TreeNode *node1Copy = que2.front();
                que1.pop();
                TreeNode *node2 = stk.top();
                stk.pop();
                
                if(node1 != nullptr && node2 != nullptr)
                {
                    if(node1->val != node2->val)
                    {
                        return false;
                    }
                    //cout<<"equal"<<endl;
                }else if ((node1 == nullptr && node2 != nullptr) || (node1 != nullptr && node2 == nullptr))
                {
                    return false;
                }
                
                if(node1 != nullptr)
                {
                    que1.push(node1->left);
                    que1.push(node1->right);
                    que2.push(node1->left);
                    que2.push(node1->right);
                }
            }
        }
        
        return true;
    }
};