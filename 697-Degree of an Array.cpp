class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        std::map<int, int> degree;
        std::set<int> numsOfDeg;
        int minLen = 0;
        
        //找到nums中所有满足dgree的数
        for(int i=0; i<nums.size(); i++)
        {
            if(degree.count(nums[i]) < 0)
            {
                degree[nums[i]] = 1;
            }else
            {
                degree[nums[i]] = degree[nums[i]] + 1;
            }
        }
        int maxFreq = 0;
        for(auto it=degree.begin(); it!=degree.end(); ++it)
        {
            
            maxFreq = max(maxFreq, it->second);
        }
        for(auto it=degree.begin(); it!=degree.end(); ++it)
        {
            if(it->second == maxFreq)
            {
                numsOfDeg.insert(it->first);
            }
        }
        //numsOfDeg是所有出现次数为maxFreq的数
        //最理想是最小长度=maxFreq，大多数是大于该值的
        minLen = nums.size();
        for(int i=0; i<nums.size(); i++)
        {
            int temp = minLen;//注意不是零
            if(numsOfDeg.count(nums[i]) > 0)
            {
                temp = 0; 
                int count = 0;
                numsOfDeg.erase(nums[i]);
                for(int j=i; j<nums.size(); j++)
                {
                    
                    if(count < maxFreq)
                    {
                        if(nums[j] == nums[i])
                        {
                            count++;
                        }
                    }else if(count >= maxFreq)
                    {
                        break;
                    }
                    
                    temp++;
                }
            }
            
            if(temp <= minLen)
            {
                minLen = temp;
            }
        }
        
        return minLen;
    }
};