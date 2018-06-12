class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int length = nums.size();
        
        std::vector<int>::iterator it = nums.begin();
        
        while(it != nums.end())
        {
            if(*it == 0)
            {
               it = nums.erase(it);
            }
            else
               it++;
        }
        
        while (nums.size() != length)
        {
            nums.push_back(0);
        }
    }
};