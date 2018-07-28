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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        queue<TreeNode*> que;
        que.push(root);
        vector<vector<int>> result;
        
        while(!que.empty())
        {
            vector<int> currList;
            int size = que.size();
            
            for(int i=0; i<size; i++)
            {
                TreeNode *node = que.front();
                que.pop();
                //currList.push_back(node->val);
                if(node != nullptr)
                {
                    currList.push_back(node->val); //该指针非空的时候，才有值。因此，写在上面一行是错误的。
                    que.push(node->left);
                    que.push(node->right);
                }
            }
            if(!currList.empty())
                result.push_back(currList);  //为啥会多出一个空的vector呢？
        }
        
        std::reverse(result.begin(), result.end());
        
        return result;
    }
};