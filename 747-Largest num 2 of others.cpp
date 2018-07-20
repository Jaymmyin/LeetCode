class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int maxValue = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            maxValue = max(maxValue, nums[i]);
        }
        int mark = -1;
        for(int i=0; i<nums.size(); i++)
        {
            if(maxValue > nums[i])
            {
                if(maxValue < 2*nums[i])
                    return -1;
            }else
            {
                if(mark == -1)
                {
                    mark = i;
                }
            }
        }
        
        return mark;
    }
};