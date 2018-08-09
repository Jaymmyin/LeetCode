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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)return 0;
        
        int max=0;
        int pathLength=0;
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            int size = que.size();
            
            for(int i=0; i<size; i++){
                TreeNode *node = que.front();
                que.pop();
                int pathLengthLeft=0;
                int pathLengthRight=0;
                //返回一个路径值，将其跟max比较
                
                if(node->left != nullptr){
                    pathLengthLeft = getPathLength(node->left);
                    pathLengthLeft++;
                }
                if(node->right != nullptr){
                    cout<<"?"<<endl;
                    pathLengthRight = getPathLength(node->right);
                    pathLengthRight++;
                }
                pathLength = pathLengthLeft + pathLengthRight;
                
                if(pathLength > max){
                    max = pathLength;
                }
                
                if(node->left != nullptr)
                    que.push(node->left);
                
                if(node->right != nullptr)
                    que.push(node->right);
            }
        }
        return max;
    }
    
private:
    int getPathLength(TreeNode* node){
        
        if(node == nullptr)
            return 0;
        
        int temp=0;
        if((node->left != nullptr) || (node->right != nullptr)){
            //cout<<"add it"<<endl;
            temp++;
        }
        
        return temp + max(getPathLength(node->left), getPathLength(node->right));
    }
};