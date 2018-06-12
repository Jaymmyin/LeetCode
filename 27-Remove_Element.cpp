class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        
        //std::vector<int>::iterator it = nums.begin();
        auto it = nums.begin(); //新手，经提醒用auto的自适应声明更方便.
        
        while(it != nums.end())
        {
            if (*it == val)
            {
                it = nums.erase(it);
            }else
            {
                it++;
            }
        }
        
        return nums.size();
    }
};