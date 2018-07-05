class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        //排序后的最大值一定要乘在内
        int len = nums.size();
        int maxProduct = nums[len-1] * nums[len-2] * nums[len-3];
        
        if(nums[0]*nums[1]*nums[len-1] > maxProduct)
        {
            maxProduct = nums[0]*nums[1]*nums[len-1];
        }
        
        return maxProduct;
    }
};