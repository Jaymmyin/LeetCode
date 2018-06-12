class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxS = nums[0], sum = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            //当前面的数求和为0时，意味着两个含义：
            //1、得到了当前的局部最优解，
            //2、前面的所有数字对后面的最大子序列的获取无意义，因此，命sum=0，新的子序列从这之后重新计算。
            if (sum < 0)
            {
                sum = 0;
            }
            
            sum = sum + nums[i];
            maxS = max(maxS, sum);
        }
        
        return maxS;
    }
};