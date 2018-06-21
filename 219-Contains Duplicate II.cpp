class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int abDiff = 0;
        if (nums.size() <= 1){return false;}    
        /*
        for(int i = 0; i < nums.size() - 1; i++)//仅仅是通过双重遍历的方法，在一些nums相当大的测试案例中会出现超时。
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if (nums[j] == nums[i])
                {
                    abDiff = j - i;
                    if (abDiff <= k)
                    {
                        return true;
                    }
                }
            }   
        }
        return false;
     */
      
      /*  
        //创建长度为k的集合的思想
        std::set<int> data;
        for (int i = 0; i < nums.size(); i++)
        {
            if (data.size() <= k)
            {
                if (data.count(nums[i]) != 0)
                {
                    return true;
                }else
                {
                    data.insert(nums[i]);
                }
            }else
            {
                auto it = data.begin();
                data.erase(it); //试了set，发现插入进集合的顺序要么是按照从小到到的顺序排列的，而不是以插入的顺序在集合中排列的。
                if (data.count(nums[i]) != 0)
                {
                    return true;
                }else
                {
                    data.insert(nums[i]);
                }
            }
        }
        
        return false;
        */
        //map 可以在时间和获取k长度集合的编号上有比较好的效果
        std::map<int, int> data;
        int j;
        for(int i=0; i<nums.size();i++)
        {
            if(data.count(nums[i]))
            {
                j = data[nums[i]];
                if(i - j <= k)
                {
                    return true;
                }else
                {
                    data[nums[i]] = i;
                }
            }else
            {
                data[nums[i]] = i;
            }
        }
        
        return false;
    }
};