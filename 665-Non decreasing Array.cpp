class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int count = 0;
        //如果做一次改变的操作，直接改vector内的值，主要就是判断改哪个值与改的大小
        for(int i=0; i < nums.size()-1; i++)
        {
            if(i == 0)
            {
                if(nums[i] > nums[i+1])
                {
                    nums[i] = nums[i+1];
                    count++;
                }
            }else if(nums[i] > nums[i+1])
            {
                if(nums[i+1] < nums[i-1])
                {
                    nums[i+1] = nums[i];
                    count++;
                }else
                {
                    nums[i] = nums[i+1];
                    count++;
                }
            }
        }
        
        if(count >= 2)
        {
            return false;
        }else
        {
            return true;
        }
        
    }
};