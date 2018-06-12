class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int len = nums.size();
        int sum = 0;
        int sum2 = 0;
        for (int i = 0; i < len; i++)
        {
            sum = sum + nums.at(i);
            sum2 = sum2 + i;
        }
        sum2 = sum2 + len;
        
        return sum2 - sum;
    }
};