class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if (target > nums.at(nums.size() - 1))
        {
            return nums.size();
        }
        
        for (int i = 0; i < nums.size(); i++){
            
            if(target == nums.at(i))
            {
                return i;
            }
            else if (target > nums.at(i))
            {
                
            }else 
            {
                return i;
            }
        }
    }
};