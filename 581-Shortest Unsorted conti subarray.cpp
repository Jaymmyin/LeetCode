class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0, end = 0;
        int min = 0, max=0;
        int minId=0, maxId=0;
        //向右找到第一个不满足大小顺序值的位置 
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                start = i;
                break;
            }
        }
        //向左找到第一个不满足大小顺序值的位置
        for(int i=nums.size()-1; i>0; i--)
        {
            if(nums[i] < nums[i-1])
            {
                end = i;
                break;
            }
        }
        if(start==0 && end==0)return 0;  //说明数组是顺序的
        
        min = nums[start];
        max = nums[end];
        minId = start;
        maxId = end;
        //找到子区间内的最大值和最小值及各自的位置
        for(int i=start; i<=end; i++)
        {
            if(nums[i] < min)
            {
                min = nums[i];
                minId = i;
            }
            
            if(nums[i] > max)
            {
                max = nums[i];
                maxId = i;
            }
        }
        //比较区间内的min跟区间左侧值的大小
        for(int i=0; i<start; i++)
        {
            if (min < nums[i])
            {
                minId = i;
                break;
            }
        }
        //比较区间内的max跟区间左侧值的大小
        for(int i=nums.size()-1; i>end; i--)
        {
            if (max > nums[i])
            {
                maxId = i;
                break;
            }
        }
        if(maxId<end)maxId=end;
        if(minId>start)minId=start;
        return maxId-minId+1;
    }
};