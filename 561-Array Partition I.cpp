class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        //1、先排序，再求基数位的和
        //2、值存入集合，再用map维护数字出现的个数(本质也是排序，可以实现，但是时间比较长，不是好方法)
        /*
        std::set<int> allValue;
        std::map<int, int> valTimes;
        std::vector<int> valSeq;
        int count=0;
        
        for(auto num:nums)
        {
            if(allValue.count(num) > 0)
            {
                valTimes[num]++; 
            }else
            {
                allValue.insert(num);
                valTimes[num] = 1;
            }
        }
        
        for(auto it=allValue.begin(); it!=allValue.end(); ++it)
        {
            valSeq.push_back(*it);
            while(valTimes[*it] != 1)
            {
                valTimes[*it]--;
                valSeq.push_back(*it);
            }
        }
        
        for(int i=0; i<valSeq.size(); i=i+2)
        {
            count = count + valSeq[i];
        }
        
        return count;
        */
        int val = 0;
        sort(nums.begin(), nums.end()); //原理leetcode 可以直接用sort, min, max这些函数
        for(int i=0; i<nums.size(); i = i+2)
        {
            val = val + nums[i];
        }
        
        return val;
    }
};