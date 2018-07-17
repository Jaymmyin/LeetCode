class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int tempLen = 1;
        int maxLen = 1;
        if(nums.size() == 0)return 0;
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i+1] > nums[i])
            {
                tempLen++;
            }else if(nums[i+1] <= nums[i])//如果两个数相等，则不满足递增的条件；[3,4,5,5,6,7,8]返回的是4，不是6
            {
                tempLen = 1;
            }
            
            if(tempLen > maxLen)
            {
                maxLen = tempLen;
            }
        }
        
        return maxLen;
    }
};