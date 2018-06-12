class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if (nums.size() == 0 | target < nums.at(0))
        {
            return 0;
        }else if(target > nums.at(nums.size() - 1))
        {
            return nums.size();
        }
        
        int s = 0;
        int e = nums.size() - 1;
        int mid = 0;
        
        while (s <= e)
        {
            mid = (s + e) / 2;
            
            if (target == nums.at(mid))
            {
                return mid;
            }else if (target > nums.at(mid))
            {
                if (s == mid)
                {
                    return s + 1;
                }
                
                s = mid;
            }else
            {
                e = mid;
                if (s == e)
                {
                    return s + 1;
                }
            }
        }
        
        
    }
};