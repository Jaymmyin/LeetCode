class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int sum=0;
        int temp=0;
        double aver=0;
        
        for(int i=0; i<k; i++)
        {
            sum = sum + nums[i];
        }
        for(int i=1; i<nums.size()-k+1; i++)
        {
            temp = 0;//每次的temp值都要置零
            for(int j=0; j<k; j++)
            {
                temp = temp + nums[i+j];//这里要记得加上i
            }
            if(temp > sum)
            {
                sum = temp;
            }
        }
        aver = (double)sum/(double)k;//这里注意计算后的精度
        
        return aver;
    }
};