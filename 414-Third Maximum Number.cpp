class Solution {
public:
    int thirdMax(vector<int>& nums) {
        
        //refer to the idea of others
        //忽略了nums本身就存在INT_MIN这个值的情况，解决办法就是 在初始和最后判断时我们用的是LONG_MIN，扩大了判断阈值
        long temp [3] = {LONG_MIN, LONG_MIN, LONG_MIN};
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]>temp[0] && nums[i] < temp[1])
            {
                temp[0] = nums[i];
            }else if(nums[i] > temp[1] && nums[i] < temp[2])
            {
                temp[0] = temp[1];
                temp[1] = nums[i];
            }else if(nums[i] > temp[2])   //这里注意不是else，是else 并且if大于temp[2]
            {
                temp[0] = temp[1];
                temp[1] = temp[2];
                temp[2] = nums[i];
            }
        }
        
        if(temp[0] == LONG_MIN)
        {
            return temp[2];
        }else
        {
            return temp[0];
        }
    }
};