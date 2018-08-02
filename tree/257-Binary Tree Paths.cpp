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
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> path;
        if(root == nullptr)
            return path;
        
        if(root->left == nullptr && root->right == nullptr){
            path.push_back(to_string(root->val));
        }else{
            if(root->left != nullptr)
                getBinaryTreePaths(root->left, path, to_string(root->val));
        
            if(root->right != nullptr)
                getBinaryTreePaths(root->right, path, to_string(root->val));
        }
        
        return path;
    }
private:
     void getBinaryTreePaths(TreeNode* node, vector<string>& path, string currPath){//用不用返回的函数实现递归
                                            //加与不加这个& 天壤之别。。。            //传入的参数是字符串，不是vector
        if(node->left ==nullptr && node->right == nullptr)
        {
            path.push_back(currPath+"->"+to_string(node->val));
            return;
        }

        if(node->left != nullptr)
            getBinaryTreePaths(node->left, path, currPath+"->"+to_string(node->val));

        if(node->right != nullptr)
            getBinaryTreePaths(node->right, path, currPath+"->"+to_string(node->val));
    }   
        
        /*
        string path="";
        vector<string> pathSet;
        if(root == nullptr)
        {
            pathSet.push_back(path);
            return pathSet;
        }else
        {
            path = path + to_string(root->val);
        }
        
        pathSet.push_back(getPath(root->left, path));
        pathSet.push_back(getPath(root->right, path));
        
        return pathSet;
        
    }
    //getPath函数返回string，但是左节点或右节点return
private:
    string getPath(TreeNode* node, string p)
    {
        if(node->left == nullptr && node->right == nullptr)
        {
            return p+"->"+to_string(node->val);
        }else
        {
            if(node->left != nullptr){
                string p1 = p+"->"+to_string(node->val);
                return getPath(node->left, p1);
            }
            
            if(node->right != nullptr){
               string p2 = p+"->"+to_string(node->val);
                return getPath(node->right, p2);
            }
        }
        */
    
};