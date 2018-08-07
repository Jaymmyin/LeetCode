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
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        if(root == nullptr)return modes;
        
        map<int, int> nums;
        getNumFromTree(root, nums);
        auto it = nums.begin();
        //std::map<int, int>::iterator it = nums.begin();
        int max = it->second;
        for(auto it=nums.begin(); it!=nums.end(); ++it){
            if(it->second > max)
                max = it->second;
        }
        
        for(auto it=nums.begin(); it!=nums.end(); ++it){
            if(it->second == max)
                modes.push_back(it->first);
        }
        
        return modes;
    }
    
private:
    void getNumFromTree(TreeNode* tree, map<int, int>& nums){
        if(tree == nullptr)
            return;
        
        if(nums.count(tree->val) > 0)
        {
            nums[tree->val]++;
        }else
        {
            nums[tree->val] = 1;
        }
        
        getNumFromTree(tree->left, nums);
        getNumFromTree(tree->right, nums);
        
    }
};