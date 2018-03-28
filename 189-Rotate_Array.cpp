class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        std::vector<int> rotateNums;
        
        int realK;
        realK = k % nums.size();
        int length = nums.size();
        
        if(realK != 0)
        {
            for(int i = length - realK; i <= length - 1; i++)
            {
                rotateNums.push_back(nums.at(i));
            }
        }
        
        for(int j = 0; j < nums.size() - realK; j++)
        {
            rotateNums.push_back(nums.at(j));
        }
        
        nums = rotateNums;
    }
};