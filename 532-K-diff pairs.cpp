class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        //首先建立数组中出现数字和其出现次数的HashMap
        std::map<int, int> store;
        int count = 0;
        if(k<0)return count;
        for(auto num:nums)
        {
            if(store.count(num) > 0)
            {
                store[num]++;
            }else
            {
                store[num] = 1;
            }
        }
        //遍历上面存储的map，而不是参数中的nums，就不会发生重复将一对统计到最后的count中的情况
        //另外，map的遍历不要跟数组的遍历弄混了，是通过迭代器实现的
        for(std::map<int, int>::iterator it=store.begin(); it!=store.end();++it)
        {
            if(k==0)
            {
                if(it->second > 1)
                {
                    count++;
                }
            }else
            {
                if(store.count(it->first + k))
                {
                    count++;
                }
            }
        }
        
        return count;
        
    }
};