class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int candidate = nums[0]; //这一题的还可以采用给向量里的数排序的方法，
        int counter = 0;         //或者按位统计哪些位是占比在半数之上的方法，这些都值得去实现，我会在leetcode上实现，这里将不再网github上更新。
        
        
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == candidate)
            {
                counter++;
            }else
            {
                if (counter == 0)
                {
                    candidate = nums[i];
                }else
                {
                    counter--;
                }
            }
        }
        
        return candidate;
    }   
};