/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
//跟前面类似，依然使用递归解决前序问题
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
    
private:
    void preorder(Node* root, vector<int>& res){
        if(!root)return;
        
        res.push_back(root->val);
        for(auto child : root->children){
            preorder(child, res);
        }
    }
};