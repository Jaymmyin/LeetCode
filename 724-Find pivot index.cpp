class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int sum = 0;
        int tempSum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            
            if(tempSum == sum-nums[i]-tempSum) //不要忘了减去前面的和tempSum
            {
                return i;
            }
            tempSum+=nums[i]; //先判断，再累加
        }
        
        return -1;
    }
};