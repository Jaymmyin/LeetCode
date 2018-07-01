class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //遍历数组中的各位数，如果以该数-1为索引在数组中的数是正数，则变换为负数；否则，不变
        //最后，剩下数组中为正数的索引+1就是数组中确实的连续正整数数字。
        std:vector<int> missInt;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] = nums[abs(nums[i]) - 1] * -1;
        }
        
        for(int i=0; i<nums.size();i++)
        {
            if(nums[i] > 0)
            {
                missInt.push_back(i+1);
            }
        }
        
        return missInt;
    }
};