class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.empty()){return 0;}
        
        int len = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[len++] = nums[i];
            }
        }
        return len;
        
        /*
        // this method takes 49ms to work out all the test cases, it is not quite efficient.    
        if(nums.size() == 0){return 0;}
        
        auto it = nums.begin();
        
        while(it != nums.end() - 1)
        {
            if(*it == *(it + 1))
            {
                it = nums.erase(it);  //这种操作是比较耗时间的
            }else
            {
                it++;
            }
        }
        
        return nums.size();
        */
        
    }
};